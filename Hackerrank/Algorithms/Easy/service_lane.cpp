/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/service-lane/problem
*/


#include <bits/stdc++.h>

using namespace std;

// This segment tree works with any kind of data and with any operation
// as long as we supply it with the operation that forms a parent from
// its two children, the identity element (the one that, when paired
// with any other data element in the formPaent function, returns the
// element), and an array of data. The function must be associative.
template <typename dataType>
class SegmentTree {
private:

    class Node {
    public:
        dataType value;
        Node* left;
        Node* right;

        Node() : value{}, left{ nullptr }, right{ nullptr } {};
        Node(dataType value) : value{ value }, 
        left{ nullptr }, right{ nullptr } {};

        void setValue(dataType value) { this->value = value;  }
    };


    dataType* values;                               
    dataType(*formParent)(dataType, dataType);      
    Node* root;                                
    int size;                                        
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

    dataType getAux(Node* ptr, int start, int end, int segmentStart, 
    int segmentEnd) {
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
            return formParent(getAux(ptr->left, start, mid, 
            segmentStart, segmentEnd),
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

    SegmentTree(dataType* values, int size, 
    dataType(*formParent)(dataType, dataType), dataType identity) : 
        values{ values }, size{ size }, formParent{ formParent }, 
        identity{identity} {
        formTree();
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

// For this implementation the operation is min
int min(int one, int two){
    return (one < two ? one : two);
}

int main(){
    int n, t;
    cin >> n >> t;
    int* arr = new int[n];
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
    }
    
    // We can use a segment tree to quickly perform queries on a segment
    // of the data
    SegmentTree<int> tree(arr, n, min, 999999);
    while(t--){
        int s, e;
        cin >> s >> e;
        cout << tree.get(s, e) << "\n";
    }
    return 0;
}