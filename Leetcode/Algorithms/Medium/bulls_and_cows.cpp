/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/bulls-and_cows/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        // These maps contain letters in each that doesn't
        // match a letter in the same position as the other's
        vector<int> s(10), g(10);
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
            }
            else{
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for(int i = 0; i <= 9; i++){
            // We add the minimum of each
            // since these are the ones that can be swapped
            cows += min(s[i], g[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};