/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/palindromic-substrings/
*/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        // This can easily be solved using dynamic programming
        // In this 2D array, we can have entry(i, j)
        // be true if the substring starting at i and
        // ending at j is a palindrome.
        // We can use the solution of smaller substrings
        // to solve those of larger ones.
        // We count the number of palindromes in this array.
        int count = 0;

        // Instead of starting at [0][0] and ending at 
        // [size-1][size-1], we start with all palidnromes
        // of size 1, then 2, etc...
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int size = 1; size <= s.size(); size++){
            // j is the start variable
            for(int j = 0; j < s.size() - size + 1; j++){

                int end = j + size - 1;

                // Base case size = 1
                if(size == 1) {
                    dp[j][end] = true;
                    count++;
                }
                // Base case size == 2
                else if(size == 2){
                    if(s[j] == s[j+1]){
                        dp[j][j+1] = true;
                        count++;
                    }
                }
                else{
                    // For a string starting at i
                    // and ending at j,
                    // we can just check if s[start] == s[end],
                    // and if the string starting at [start+1]
                    // and ending at [end-1] is a palindrome
                    if(s[j] == s[end] && dp[j+1][end-1]){
                        dp[j][end] = true;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};