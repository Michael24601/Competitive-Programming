/*
    Website: Leetcode
    Difficulty: Easy
    Language: c++
    Link: https://leetcode.com/problems/length-of-last-word/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string::reverse_iterator it = s.rbegin();
        int ans{};
        for(; it != s.rend() && (*it != ' ' || ans == 0); it++){
            if(*it != ' ')
                ans++;
        }
        return ans;
    }
};