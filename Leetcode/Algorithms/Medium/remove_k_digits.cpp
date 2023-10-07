/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/remove-k-digits/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string removeLeadingZeros(const string& str) {
        size_t firstNonZero = str.find_first_not_of('0');
        if (firstNonZero != string::npos) {
            return str.substr(firstNonZero);
        }
        return "0";
    }

    string removeKdigits(string s, int k) {
        // We each time remove the first number larger than the next
        // if not, we remove the first number = to the next
        // Even with many k, we will only need a single pass
        for(int i  = 0; i < s.size() - 1 && k > 0;){
            if(s[i] > s[i+1]){
                s.erase(i, 1);
                // Check the last index in case erasing this one changed something
                if(i > 0) i--;
                k--;
            }
            else{
                i++;
            }
        }
        // Finally, we just remove the rest of the elements off the end.
        // This is because at this point, if we still have some ks left,
        // we've already done the whole string, meaning it is already
        // sorted in increasing order, so we remove the largest digits.
        while(k--){
            s.erase(s.size()-1, 1);
        }
        return removeLeadingZeros(s);
    }
};