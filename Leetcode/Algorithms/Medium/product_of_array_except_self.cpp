/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/product-of-array-except-self/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // We can define suffix and prefix arrays
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        vector<int> suffix(nums.size());
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i];
            suffix[nums.size() - i - 1] = 
                suffix[nums.size() - i] * nums[nums.size() - i - 1];
        }

        // Then, for the answer[i], we just multiply
        // prefix[i-1] * suffix[i+1] unless it's an edge
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0)
                ans[i] = suffix[i + 1];
            else if(i == nums.size() - 1)
                ans[i] = prefix[i - 1];
            else
                ans[i] = prefix[i-1] * suffix[i+1];
        }

        return ans;
    }
};