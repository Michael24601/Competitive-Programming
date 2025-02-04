/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/shortest-common-supersequence/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        // We can use dp[i][j]
        // where dp[i][j] is the longest subsequence in common
        // between s1 and s2 up to i and j characters.
        // So dp[0][0] = "".
        vector<vector<string>> dp(s1.size()+1, vector<string>(s2.size()+1));
        dp[0][0] = "";

        for(int i = 0; i <= s1.size(); i++){
            // To save on memory costs, we can can clear rows
            // we no longer need
            if(i >= 2) dp[i-2].clear();

            for(int j = 0; j <= s2.size(); j++){
                if(i == 0 || j == 0){ 
                    dp[i][j] = "";
                }
                else if (s1[i-1] == s2[j-1]){
                    // If the current characters are equal,
                    // then the longest subsequence 
                    // is the last longest subsequence
                    // without this character + 1
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }
                else{
                    // Otherwise, it's either the longest
                    // subsequence up to i-1 and j, 
                    // or up to i and j-1
                    // Since the current character won't
                    // be added
                    if(dp[i-1][j].size() > dp[i][j-1].size()){
                        dp[i][j] = dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        
        string s = dp[s1.size()][s2.size()];
        // We can now build the supersequence
        // We can do it by first copying as many characters
        // from s1 as we can until we reach the point where
        // s1[i] == s[k].
        // We then do the same with s2[j] until s2[j] == s[k].
        // We repeat this until s is depleted.
        // After that we copy what is left of s1 and s2;
        string super = "";
        int i = 0, j = 0;
        for(int k = 0; k < s.size(); ){
            if(s1[i] == s[k] && s2[j] == s[k]){
                super += s[k];
                k++;
                i++;
                j++;
            }
            else if (s1[i] == s[k]){
                super += s2[j];
                j++;
            }
            else{
                super += s1[i];
                i++;
            }
        }
        // We then just copy what is left
        super += s1.substr(i);
        super += s2.substr(j);
        return super;
    }
};