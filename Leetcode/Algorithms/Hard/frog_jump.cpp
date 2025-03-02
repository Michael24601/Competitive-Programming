/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/frog-jump/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        // Since we have n stones, the jump size is at most n
        // (we have at most n-1 jumps, starting with 1, so the jump
        // size goes to n).
        // Here dp[i][j] is true if we can reach the ith stone 
        // in a jump of size j (from anywhere).
        // To get that, we just check if dp[a][j+1], dp[a][j],
        // or dp[a][j-1] are true, where a is the index of a stone
        // at stones[i]-j.
        // We can use a hashmap to find a quickly.
        // If dp[n-1][j] is true for any j, then we can reach the
        // last stone.

        // We always set dp[0][0] to true.

        map<int, int> m;
        for(int i = 0; i < stones.size(); i++){
            m[stones[i]] = i;
        }

        vector<vector<bool>> dp(stones.size(), vector<bool>(stones.size()));
        dp[0][0] = true;

        // We can start both i and j at 1, all other values
        // excpet dp[0][0] are false.
        for(int i = 1; i < stones.size(); i++){
            for(int j = 1; j < stones.size(); j++){

                int a;
                if (m.count(stones[i]-j)) {
                    a = m[stones[i]-j];

                    bool value = false;
                    value = value || dp[a][j];
                    if(j-1 >= 0){
                        value = value || dp[a][j-1];
                    }
                    if(j+1 < stones.size()){
                        value = value || dp[a][j+1];
                    }
                    dp[i][j] = value; 
                }
                else{
                    dp[i][j] = false;
                }

                if(i == stones.size() - 1 && dp[i][j]){
                    return true;
                }

            }
        }

        return false;
    }
};