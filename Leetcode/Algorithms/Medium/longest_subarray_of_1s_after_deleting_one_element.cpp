/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }

        // We can create two arrays a, and b:
        // a[i] contains the largest subarray
        // of 1s ending at i-1,
        // and b[i] contains the largest subarray
        // containing 1s starting at i+1.
        // So if index i was deleted, the subarray
        // would be a[i] + b[i] length. Our goal is
        // to find the max of a[i] + b[i].

        // Now to calculate each array.
        // a[i] = a[i-1] + 1 if nums[i-1] == 1,
        // since the subarray of 1s continues,
        // and is 0 otherwise.
        // Same for b[i] = b[i+1] + 1,
        // only if nums[i+1] == 1.

        // Note that even though it appears we can use
        // a sliding window and not store the whole array,
        // we have to store the values, since b[i] and
        // a[i] are calculated in reverse order, so we can't
        // calculate the max in real time.

        vector<int> a(nums.size());
        vector<int> b(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i-1] != 1){
                a[i] = 0;
            }
            else{
                a[i] = a[i-1] + 1; 
            }

            if(i == 0 || nums[nums.size() - i] != 1){
                b[nums.size() - 1 - i] = 0;
            }
            else{
                b[nums.size() - 1 - i] = b[nums.size() - i] + 1;
            }
        }

        // We then find the max
        int max = -1;
        for (int i = 0; i < nums.size(); i++){
            if(max < (a[i] + b[i])){
                max = a[i] + b[i];
            }
        }

        return max;
    }
};