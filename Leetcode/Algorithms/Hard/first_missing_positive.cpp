/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/first-missing-positive/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // There are n integers in nums.
        // Suppose now we were to have an array with
        // size n where arr[i] = i+1 containing the
        // numbers in nums (starting with arr[0] = 1)
        // If arr[i] != i+1, we can assume i+1 isn't
        // in nums. So the first such number is the
        // smallest positive integer.
        // If all exist, then the next number, n+1,
        // is the missing number.
        // We can use nums as arr, to avoid using more
        // space.
        for(int i = 0; i < nums.size(); i++){
            // This loop continues swapping until a
            // cycle of numbers is done (numbers that,
            // when permuted, end up in the correct placement).
            // The loop being nested doesn't change the fact
            // that we loop over each number once, so it
            // remains O(n)
            while (nums[i] > 0 && nums[i] <= nums.size() 
                && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};