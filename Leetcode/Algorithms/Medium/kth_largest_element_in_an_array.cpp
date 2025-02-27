/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // We can create a sliding window of size k,
        // and use a heap initialized with k elements,
        // then add one element at a time and remove one
        // element to maintain the size of the heap.

        // We want the kth largest element, but we can't use a maxHeap;
        // using a max heap with k elements sounds like a solution
        // but everytime we add an element to the k we already have,
        // we want to remove the smallest, not largest.
        // Instead, with a min heap, if we remove the minimal element
        // each time, we eventually end up with the largest k
        // elements. If we then return the min, we have the kth largest.

        // Using a heap, the time is nlog(k).
        // Had we just sorted the array, it would have been nlog(n).

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0; i < k; i++){
            minHeap.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++){
            minHeap.push(nums[i]);
            // Removes (k+1)th largest element
            minHeap.pop();
        }

        return minHeap.top();
    }
};