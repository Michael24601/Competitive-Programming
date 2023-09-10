/*
    Website: leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/reverse-integer/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x < 0)
            std::reverse(s.begin() + 1, s.end());
        else if (x > 0)
            std::reverse(s.begin(), s.end());

        // We can't cast the string to a long in order to
        // check if it's longer than an int can handle,
        // and casting it to an int gives an error, so a try
        // catch is a reasonable solution.
        try{
            x = stoi(s);
        } catch(...){
            x = 0;
        }
        
        return x;
    }
};