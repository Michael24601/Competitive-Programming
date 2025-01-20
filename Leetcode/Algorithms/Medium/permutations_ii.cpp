/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/permutations-ii/
*/


#include <bits/stdc++.h>

class Solution {
public:
       vector<vector<int>> permuteUnique(vector<int>& nums) {

        int factorial[9]{1, 1, 2, 6, 24, 120, 720, 5040, 40320};
        // Using a set to ensure no duplicates are outputted.
        // Using set instead of ordered set as it does not require
        // elements to be hashable.
        set<vector<int>> p;
        vector<vector<int>> perms;

        int i = 0;
        do {
            if (p.find(nums) == p.end()) {
                p.insert(nums);
                perms.push_back(nums);
            }
            i++;
            next_permutation(nums.begin(), nums.end());
        } while (i < factorial[nums.size()]);

        return perms;
    }
};