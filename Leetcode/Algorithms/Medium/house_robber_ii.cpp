/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/house-robber-ii/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        // We can solve this like we did in the original non-circular
        // version, but we solve it twice; one without the first house,
        // once without the last, then pick the best.

        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        // p1 is without the last, p2 is without the first

        vector<int> p1(nums.size()-1), p2(nums.size()-1);

        p1[0] = nums[0];
        p1[1] = max(nums[0], nums[1]);
        for(int i = 2; i < p1.size(); i++){
            p1[i] = max(p1[i-1], p1[i-2]+nums[i]);
        }

        p2[0] = nums[1];
        p2[1] = max(nums[1], nums[2]);
        for(int i = 2; i < p2.size(); i++){
            p2[i] = max(p2[i-1], p2[i-2]+nums[i+1]);
        }

        return max(p1[p1.size()-1], p2[p2.size()-1]);
    }
};