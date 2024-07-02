/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/next-permutation/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = is_sorted_until(nums.rbegin(), nums.rend());

        // In the case where we are at the last permutation
        if (it == nums.rend()) {
            reverse(nums.begin(), nums.end());
        } else {
            auto next_it = upper_bound(nums.rbegin(), it, *it);
            swap(*it, *next_it);
            reverse(nums.rbegin(), it);
        }
    }
};