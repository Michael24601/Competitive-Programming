/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/longest-increasing-subsequence/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // We can use dynamic programming to solve this, creating an array
        // p such that p(k) is the longest increasing subsequence ending 
        // at k.
        // We know that p(0) = 1 (only one number).
        // The final result will be the largest such p(k).
        // To build p, we search through all previous indexes such that 
        // num(n) smaller than num(k), and pick the one with the largest p(n).
        // Then p(k) = p(n) + 1. If none are larger, and p(k) = 1 (starting a
        // new sequence over).

        vector<int> p(nums);
        p[0] = 1;
        int max = -1;
        for(int i = 1; i < nums.size(); i++){
            int maxP = -1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && p[j] > maxP)
                    maxP = p[j];
            }
            // None smaller were found before index i
            if(maxP == -1) p[i] = 1;
            // A smaller number with the largest subsequence was found before
            // index i
            else p[i] = maxP + 1;

            if(p[i] > max) max = p[i];
        }

        // If no maximum is found, it means only one number was given,
        // so we return 1
        return (max == -1 ? 1 : max);
    }
};