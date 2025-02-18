/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/minimum-size-subarray-sum/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        if(nums.size() == 1){
            if(nums[0] >= target) return 1;
            else return 0;
        }


        // We won't use dynamic programming to solve
        // the problem, but it is useful to imagine us using
        // it for now.

        // First assume we have a prefix sum pref;
        // where pref[i] is the sum from index 0 to i.

        // Finding the smallest sub array with the
        // desired sum, means finding the two closest
        // entries in the prefix sum whose difference
        // is at least that sum.
        // We can do this with dp,
        // where dp[i] is index of the closest index
        // j, j > i, such that pres[j] - pres[i]
        // is at least sum.

        // We can first find dp[0] as a base case
        // by just iterating; if no sum is found
        // then we return 0 as it is impossible.
        // Otherwise, we know that pres[i]
        // is larger than pres[i-1], so the index
        // j such that pres[j] - pres[i] >= sum
        // is at least as large as that of pres[i-1]
        // (stored in dp[i-1]), so we can start 
        // searching from there. That way the 
        // time complexity is at most O(n),
        // and has space O(n) (prefix sum array and dp array
        // are both linear space).

        // Note however, that because we are always using
        // dp[i-1] in our solution for dp[i],
        // we don't need to store it in an array.
        // We can simulate the dp array using just two variables:
        // dp and min. So we can save space and avoid memoization.

        // It's the same for the prefix sum: we only need the sum
        // up to the index we're working on (since we're only
        // ever visiting each index once starting from d[i-1]);
        // we can thus avoid a prefix sum array and instead have 
        // two variables:
        // prefi for the sum up to current index i
        // and prefj index for the sum up to the index j
        // (end of the sum interval).

        // So the solution is O(1) space and O(n) time,
        // and uses a sliding window approach that sort of
        // resembles dynamic programming in that the last
        // solution is used to compute the next.

        int dp;
        int min;
        int prefi = nums[0];
        int prefj = 0;

        // First we set dp[0]
        for(int i = 0; i < nums.size(); i++){
            prefj += nums[i];
            if(prefj >= target){
                dp = i;
                break; 
            }
            // If we reach end and no sum is large enough
            else if (i == nums.size() - 1){
                return 0;
            }
        }
        min = dp;

        // Now we do dp loop
        // Note that as soon as we reach an index starting from
        // which no sum is large enough to reach our target,
        // we stop updating dp, as we've reached the last
        // suitable index.

        for(int i = 1; i < nums.size(); i++){

            // dp is currently dp[i-1]
            int j = dp;

            while(prefj - prefi < target){
                j++;

                if(j == nums.size()){
                    break;
                }

                // Since index j is incremented
                // we udpate pref with the newest sum
                prefj += nums[j];
            }
            if(j == nums.size()){
                // This means that we've reached the
                // last index i for which we have
                // a large enough sum
                break;
            }
            else{
                // Update dp with dp[i]
                dp = j;
                if(dp - i < min){
                    min = dp - i;
                }
            }

            // We update prefi with the newest sum
            // since i is incremented
            prefi += nums[i];
        }

        // We return min + 1 because dp[i] - i + 1 is the 
        // length of the interval.
        return min + 1;
    }
};