/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/permutations/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int factorial[7]{1, 1, 2, 6, 24, 120, 720};
        vector<vector<int>> perms(factorial[nums.size()]);

        int i = 0;
        do {
            perms[i] = nums;
            i++;
            next_permutation(nums.begin(), nums.end());
        } while (i < perms.size());

        return perms;
    }
};