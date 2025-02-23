/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/minimum-path-sum/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
    
            // We can get to any cell we want by just going
            // down or right; we never have to go left or up,
            // and if a path requires that, it is not optimal,
            // and we can shorten it, which makes it more minimal,
            // since all numbers are positive.
            // This means we can get to any cells either from the
            // cells above it, or the one to its left:
            // We can save a 2D grid dp where dp[i][j] is the minimal
            // score to cell (i, j).
            // We can get the minimal score by finding the minimum
            // of dp[i][j-1] and dp[i-1][j] (whichever one gets
            // us to (i, j) with a smaller score).
            // The only edge cases are the literal edges when
            // i = 0 or j = 0: in these cases, we only have one
            // option of a cell that gets us there.
    
            vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
            for(int i = 0; i < grid.size(); i++){
                for(int j = 0; j < grid[i].size(); j++){
                    if(i == 0 && j == 0){
                        dp[i][j] = grid[i][j];
                    }
                    else if(i == 0){
                        dp[i][j] = dp[i][j-1] + grid[i][j];
                    }
                    else if(j == 0){
                        dp[i][j] = dp[i-1][j] + grid[i][j];
                    }
                    else{
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                    }
                }
            }
    
            return dp[grid.size() - 1][grid[0].size()-1];
        }
    };