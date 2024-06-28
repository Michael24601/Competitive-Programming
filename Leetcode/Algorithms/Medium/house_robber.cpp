/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/house-robber/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // This can be solved using dynamic programming.
        // Suppose that p(k) is the max amount of money we can get
        // by robbing the first k houses, and q(k) is the amount in
        // house k.
        // Then p(k) = max(p(k-1), p(k-2) + q(k)),
        // which means that it's the larger of two options: skipping
        // house k-1 in order to rob house k, in which case we would
        // have to have robbed the optimal number of houses up to k-2,
        // or, skipping house k-1 is not profitable enough, in which
        // case we skip house k instead.
        // We start with p(0) = q(0) obviously.
        // Also, for p(1), since there is no p(1-2),
        // p(1) is just the max of p(1) and p(0).
        
        if(nums.size() == 1) return nums[0];

        vector<int> p(nums.size());
        p[0] = nums[0];
        p[1] = max(nums[0], nums[1]);
        for(int i = 2; i < p.size(); i++){
            p[i] = max(p[i-1], p[i-2]+nums[i]);
        }
        return p[p.size()-1];
    }
};