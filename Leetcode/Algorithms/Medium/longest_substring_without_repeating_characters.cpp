/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s == "") return 0; 
        
        // In the dp solution, dp[i]
        // is the length of the longest substring
        // with the mentioned quality ending at
        // index i.
        // We can use it to calculate dp[i+1]:
        // The size of the unique substring is at
        // most 26. We can search in dp[i]'s
        // substring from an occurence of s[i+1].
        // If it doesn't occur, dp[i+1] = dp[i] + 1.
        // If it does, dp[i+1] is the section of
        // dp[i] after the occurence plus the character
        // s[i+1].
        // The time is O(26 * n) = O(n).
        vector<int> dp(s.size());
        dp[0] = 1;
        for(int i = 1; i < s.size(); i++){
            int l = dp[i-1];
            int index = -1;
            for(int j = 0; j < l; j++){
                int k = i - j - 1;
                if(s[k] == s[i]){
                    index = k;
                    break;
                }
            }
            if(index == -1){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = (i - index);
            }
        }

        // We then return the largest
        int max = *max_element(dp.begin(), dp.end());
        return max;
    }
};