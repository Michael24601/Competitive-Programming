/*
    Website: Leetcode
    Difficulty: Easy
    Language: c++
    Link: https://leetcode.com/problems/nim-game
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canWinNim(short n) {
        // Range 1-3 is winning because we can force a win.
        // Stone 4 is losing because no matter what we take, the other player 
        // will be in the 1-3 winning range
        // 5-7 is a winning range because the player can force the other
        // to be at 4, which is losing.
        // Stone 8 is losing because no matter what you take, the other player
        // will be in 5-7, a winning range.
        // If we continue like this, we realize we can force a win 
        // as long as continuously place the other player in a losing stone,
        // meaning we have to start at a winning (non mod 4) stone.
        return n%4 != 0;
    }
};