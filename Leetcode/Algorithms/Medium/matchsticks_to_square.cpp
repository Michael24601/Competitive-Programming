/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/matchsticks-to-square/
*/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    // Nums is the array of numbers, and it remains unchanged,
    // so we can afford to send it by reference.
    // On the other hand, subset is the sum in each subset
    // Index is the current index we're disposing of,
    // and target is teh target sum for each subset.
    bool canPartition(
        vector<int>& nums, vector<int>& subset, 
        int index, int target
    ) {
    if (index == nums.size()) {
        // If all the subsets have the target sum we're done
        return subset[0] == target && subset[1] == target &&
               subset[2] == target && subset[3] == target;
    }

    // Otherwise, we try giving the current held number
    // in the array to each of the 4 subsets.
    // We then backtrack and try giving the sum to another
    // pile.
    for (int i = 0; i < 4; ++i) {
        if (subset[i] + nums[index] <= target) {
            subset[i] += nums[index];
            if (canPartition(nums, subset, index + 1, target)) {
                return true;
            }
            subset[i] -= nums[index];  // Backtrack
        }

        // Done for pruning reasons (if all subsets have 0 in them,
        // we create redundant computation if we try them all
        // and they're the same).
        if (subset[i] == 0) {
            break;
        }
    }
    return false;
}

    bool makesquare(vector<int>& nums) {
        // We need a way to partition the matchsticks
        // into 4 piles such that each pile has the 
        // the same sum. That's the same as making
        // a square.

        // We also know that each pile has to be the
        // quarter of the total sum of the array
        // since we need to use all the matchsticks.
        long long sum = 0;
        for(long long i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        // If the sum is not divisible by 4, then it 
        // is not possible.
        if(sum % 4 != 0) return false;

        // Another case that makes it impossible is
        // if we can't divide any of the piles in such
        // a way that they all have a quarter of the size
        // (since we can't break matchsticks).
        // We can use the partional dynamic programming
        // algorithm, this time for 4 partitions.
        int targetSum = sum / 4;
        int n = nums.size();

        // Our algoritm used backtracking, which means that
        // we add an element to a subset, and if it exceeds the
        // limit, it means we messed up, and backtrack to an
        // earlier step and give the element to another subset.
        // Knowing that, it is more efficient to have the elements
        // in decreasing order.
        sort(nums.begin(), nums.end(), greater<int>());

        // We have 4 subsets, all initialized with a sum of 0
        // We don't need to keep track of which elements are in
        // which subset, only the index of the current matchstick
        // we're disposing of, and sum of each subset up to this
        // point.
        vector<int> subset(4, 0);
    
        // Note that this algorithm is a very famous NP-Complete
        // problem, so it is exponential time.
        return canPartition(nums, subset, 0, targetSum);
    }
};