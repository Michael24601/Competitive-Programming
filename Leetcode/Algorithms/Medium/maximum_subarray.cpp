/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/maximum-subarray/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            // We can a dynamic programming like approach:
            // If dp[i] contains the sum of the largest subaaray
            // ending at i, then we can set dp[0] = nums[0],
            // then, dp[i] will be equal to this:
            // If dp[i-1] is negative, then it is always better to
            // discard the largets subarray up to dp[i-1] and start
            // fresh with dp[i] = nums[i].
            // Else, if positive, we have to add nums[i] to dp[i-1].
            // Since the largest subarray is one of these, we
            // pick the max of dp.
            // This is Kadane's algorithm.
            
            // However, note that since dp[i] only ever depends on
            // dp[i-1], and since we need them max of all the dp values,
            // we don't need to save the whole array:
            // we can just use two variables: one for dp[i-1],
            // and one for the max, calculated in real time.
    
            // dp[i-1] starting at dp[0]
            int dp = nums[0];
            int max = dp;
    
            // Dp loop
            for(int i = 1; i < nums.size(); i++){
                // This is dp[i]
                int temp;
                if(dp < 0){
                    temp = nums[i];
                }
                else{
                    temp = nums[i] + dp;
                }
    
                // We then set dp[i-1] to dp[i]
                dp = temp;
    
                if(dp > max){
                    max = dp;
                }
            }
    
            return max;
        }
    };