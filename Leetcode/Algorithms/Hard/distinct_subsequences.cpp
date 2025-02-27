/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/distinct-subsequence/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int numDistinct(string s, string t) {
        // Here dp[i][j] is the number of possible times
        // t up to index i appears as a subsequence in
        // s up to index j.
        // So for dp[i][j], if s[i] == t[i], we can either
        // include the character in the subsequence or not
        // so dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
        // (dp[i-1][j-1] indicates we did include it,
        // while dp[i][j-1] suggests we did not include it).
        // Else if s[i] != t[i], then we can't add it to the
        // subsequence, so dp[i][j] = dp[i][j-1].
        vector<vector<unsigned long long>> dp(
            t.size(), vector<unsigned long long>(s.size())
        );

        for(int i = 0; i < t.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(i == 0 && j == 0){
                    if(s[j] == t[i]){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                // If we have one letter t, 
                // then we just want the number of times
                // it appears in s up to this point.
                else if(i == 0){
                    if(s[j] == t[i]){
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
                // If we have less characters in s than
                // are in t, it's an automatic 0.
                else if (j < i){
                    dp[i][j] = 0;
                }
                else{
                    if(s[j] == t[i]){
                        dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        
        return dp[t.size()-1][s.size()-1]; 
    }
};