#ifndef SEGMENT_TREE
#define SEGMENT_TREE

#include <bits/stdc++.h>

// Node that the operation used to form node parents must be associative and
// must have an identity value (a value for which the operation being invoked
// on an element and the idenity produces the element as is)
// In other words, we need something that more or less resembeles a Group:
// A set of elements on which a binary operator is applied; the operator must
// be associative and must be aossicated with an idenity element.
template <typename dataType>
class SegmentTree {
private:

	class Node {
	public:
		dataType value;
		Node* left;
		Node* right;

		Node() : value{}, left{ nullptr }, right{ nullptr } {};
		Node(dataType value) : value{ value }, left{ nullptr }, right{ nullptr } {};

		void setValue(dataType value) { this->value = value;  }
	};


	dataType* values;								// Array of values
	dataType(*formParent)(dataType, dataType);		// Function that forms parent from two child node dataTypes
	Node* root;										// Root of tee
	int size;										// Array size
    dataType identity;


	dataType formTreeAux(Node* ptr, int start, int end) {
		int mid = (end + start) / 2;
		ptr->left = new Node();
		ptr->right = new Node();

		// if leaf
		if (mid - start == 0) {
			ptr->left->setValue(values[mid]);
		}
		else {
			ptr->left->setValue(formTreeAux(ptr->left, start, mid));
		}

		// if leaf
		if (end - mid - 1 == 0) {
			ptr->right->setValue(values[mid+1]);
		}
		else {
			ptr->right->setValue(formTreeAux(ptr->right, mid+1, end));
		}

		ptr->setValue(formParent(ptr->left->value, ptr->right->value));

		return ptr->value;
	}


	void formTree() {
		root = new Node();
		formTreeAux(root, 0, size - 1);
	}


	void displayAux(std::ostream& out, Node* ptr, int indent) {
		if (ptr == nullptr) {
			return;
		}
		else {
			displayAux(out, ptr->right, indent + 8);
			out << std::setw(indent) << " " << ptr->value << "\n";
			displayAux(out, ptr->left, indent + 8);
		}
	}


	dataType getAux(Node* ptr, int start, int end, int segmentStart, int segmentEnd) {
		int mid = (end + start) / 2;
		// if whithin
		if (start >= segmentStart && end <= segmentEnd) {
			return ptr->value;
		}
		else if (start > segmentEnd || end < segmentStart) {
            // The value that is sent when an interval is empty must be the
            // identity of the operation: for a sum, it is 0, for a minimum
            // operation, it is the maximum possible number ... etc.
			return identity;
		}
		else {
            // The operation must be associative, for this to work
			return formParent(getAux(ptr->left, start, mid, segmentStart, segmentEnd),
				getAux(ptr->right, mid + 1, end, segmentStart, segmentEnd));
		}
	}


    void updateAux(Node* ptr, int start, int end, int index){
        if(ptr->left == nullptr && ptr->right == nullptr){
            ptr->value = values[index];
        }
        else{
            int mid = (start + end) / 2;
            if (index <= mid) {
                updateAux(ptr->left, start, mid, index);
            }
            else if (index > mid) {
                updateAux(ptr->right, mid+1, end, index); 
            }
            ptr->value = formParent(ptr->left->value, ptr->right->value);
        }
    }


public:

	SegmentTree(
            dataType* values, int size,
            dataType(*formParent)(dataType, dataType), dataType identity
        ) : values{ values }, size{ size }, formParent{ formParent },
        identity{identity} {
		formTree();
	}


	void display(std::ostream& out) {
		displayAux(out, root, 0);
	}


	dataType get(int start, int end) {
		return getAux(root, 0, size -1, start, end);
	}


	void update(dataType newValue, int index) {
        if(index >= 0 && index < size){
            values[index] = newValue;
            updateAux(root, 0, size-1, index);
        }
        else{
            std::cerr << "Wrong index.\n";
        }
	}
};

#endif