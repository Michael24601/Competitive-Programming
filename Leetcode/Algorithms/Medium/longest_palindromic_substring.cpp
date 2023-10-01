/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/longest-palindromic-substring/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1){
            return s;
        } 
        else if (s.size() == 2 && s[0] == s[1]){
            return s;
        }

        string maxSub;

        for(size_t i = 0; i < s.size(); i++){
            for(int j = 0; j < min(i, s.size() - i - 1) + 1; j++){
                // Check for odd sized palindrome
                if(s[i-j] != s[i+j]){
                    break;
                }
                else{
                    if(2*j + 1 > maxSub.size()){
                        maxSub = s.substr(i-j, 2*j + 1);
                    }
                }
            }

            if(i < s.size() - 1){
                for(int j = 0; j < min(i, s.size() - i) + 1; j++){
                    // Checks for even sized palindrome (where i is index before
                    // which we check the crevice (which is why we stop before
                    // s.size() - 1))
                    if(s[i-j] != s[i+j+1]){
                        break;
                    }
                    else{
                        if(2*(j+1) > maxSub.size()){
                            maxSub = s.substr(i-j, 2*(j+1));
                        }
                    }
                }
            }
        }
        return maxSub;
    }
};