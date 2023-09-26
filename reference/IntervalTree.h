#ifndef INTERVAL_TREE
#define INTERVAL_TREE

#include <bits/stdc++.h>

using namespace std;

// Used in order to make queries on which intervals overlap with a given
// interval or point.

// Define the Interval Tree Node structure
struct IntervalNode {
    int low;
    int high;
    IntervalNode* left;
    IntervalNode* right;
    int index; // Optional, used to identiy nodes

    IntervalNode(int l, int h, int index) : low(l), high(h), index(index), 
        left(nullptr), right(nullptr) {}
};

// Function to insert an interval into the Interval Tree
IntervalNode* insert(IntervalNode* root, int low, int high, int index) {
    if (root == nullptr) {
        return new IntervalNode(low, high, index);
    }

    // Choose the appropriate subtree based on the low endpoint
    if (low < root->low) {
        root->left = insert(root->left, low, high, index);
    } else {
        root->right = insert(root->right, low, high, index);
    }

    return root;
}

// Function to perform interval-based query that checks for ranges that overlap
// the given range. For doing a point query, we can send the same value for
// low and high.
void query(IntervalNode* root, int low, int high) {
    if (root == nullptr) {
        return;
    }

    // Check if the current interval overlaps with the query interval
    if (root->low <= high && root->high >= low) {
        // Perform desired operation on the overlapping interval
        std::cout << "[" << root->low << ", " << root->high << "]" << std::endl;
    }

    // Recursively search both subtrees
    if (root->left != nullptr && root->left->high >= low) {
        query(root->left, low, high);
    }
    query(root->right, low, high);
} 

#endif