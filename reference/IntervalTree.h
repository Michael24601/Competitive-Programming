#ifndef INTERVAL_TREE
#define INTERVAL_TREE

#include <bits/stdc++.h>

using namespace std;

// Class for an interval tree.
// Used in order to make queries on which intervals overlap with a given
// interval or point.
// Each interval can have an index, which is used to identify them.

class IntervalTree {
private:

    // This part defines the interval tree node
    struct IntervalNode {
        int low;
        int high;
        IntervalNode* left;
        IntervalNode* right;

        // Optional, used to identiy the nodes in case we need a unique
        // identifier
        int index; 

        IntervalNode(int l, int h, int index) : low(l), high(h), index(index), 
            left(nullptr), right(nullptr) {}
    };

    // Root of the tree
    IntervalNode* root;

    // Function to insert an interval into the Interval Tree
    IntervalNode* insert(IntervalNode* ptr, int low, int high, int index) {
        if (ptr == nullptr) {
            return new IntervalNode(low, high, index);
        }

        // Choose the appropriate subtree based on the low endpoint
        if (low < ptr->low) {
            ptr->left = insert(ptr->left, low, high, index);
        } else {
            ptr->right = insert(ptr->right, low, high, index);
        }

        return ptr;
    }


    // Function to perform interval-based query that checks for ranges that overlap
    // the given range. For doing a point query, we can send the same value for
    // low and high.
    void query(IntervalNode* ptr, int low, int high) {
        if (ptr == nullptr) {
            return;
        }

        // Check if the current interval overlaps with the query interval
        if (ptr->low <= high && ptr->high >= low) {
            // In this part here, we can perform desired operation on the 
            // overlapping interval. We can modify the function inputs and
            // output as well to reflect our needs.
            cout << "[" << ptr->low << ", " << ptr->high << "]\n";
        }

        // Recursively search both subtrees
        if (ptr->left != nullptr && ptr->left->high >= low) {
            query(ptr->left, low, high);
        }
        query(ptr->right, low, high);
    } 

public:

    // No arg constructor
    IntervalTree() : root{nullptr} {}

    // Function to insert an interval into the Interval Tree
    // Publicly available
    void insert(int low, int high, int index) {
        insert(root, low, high, index);
    }

    // Query an interval (prints the interval here, but we can modify it to 
    // define behavior according to requirements). Publicly available.
    void query(int low, int high) {
        query(root, low, high);
    } 

};


#endif