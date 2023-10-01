/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/dungeon-game/
*/


#include <bits/stdc++.h>

using namespace std;

// This is a classic case of a program that needs a dynamic programming
// table to be solved, but with some twists.

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int n = dungeon.size(), m = dungeon[0].size();

        // In the normal version, we are looking for the maximum score we
        // can achieve, so for any square not in the top or left row/column,
        // we tend to have dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j],
        //  where the value of dp[a][b] is always the max score we can get
        // when reaching this point. 

        // However, we don't want the max score in this version.
        // our goal is to find the path with the least small minimum value
        // we reach on it, so instead, we will have a pair in each dp cell.
        // One is the minimum value in the road we reach up to this point,
        // and the other is as before the score up to this point.
        // Each time we update the score in the same way, and if the score
        // dips below the minimum, we also update the minimum of this cell
        // accordingly, otherwise it is the same as the last cell.
        // We make the final score not based on the final score, but based
        // on which number out of that which we get from subtracting this cell's 
        // score from the total score of dp[i-1][j] and dp[i][j-1] is larger 
        // (the new minimum). If both are equal, or if the minimum does not
        // change, we pick the larger score (this probably makes no difference)
        // but to be on the safe side.

        // This was the approach:
        /*
            vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(m));
            for(int i = 0; i < n ; i++){
                for(int j = 0; j < m; j++){
                    if(i == 0 && j == 0){
                        dp[i][j] = make_pair(dungeon[i][j], dungeon[i][j]);
                    } else if (i == 0){
                        int mini = min(dp[i][j-1].second, dp[i][j-1].first + dungeon[i][j]);
                        dp[i][j] = make_pair(dp[i][j-1].first + dungeon[i][j], mini);
                    } else if (j == 0){
                        int mini = min(dp[i-1][j].second, dp[i-1][j].first + dungeon[i][j]);
                        dp[i][j] = make_pair(dp[i-1][j].first + dungeon[i][j], mini);
                    } else{
                        int min1 = min(dp[i][j-1].second, dp[i][j-1].first + dungeon[i][j]);
                        int min2 = min(dp[i-1][j].second, dp[i-1][j].first + dungeon[i][j]);
                        int score1 = dp[i][j-1].first + dungeon[i][j];
                        int score2 = dp[i-1][j].first + dungeon[i][j];

                        if(min1 > min2){
                            dp[i][j] = make_pair(score1, min1);
                        } else if (min1 <= min2){
                            dp[i][j] = make_pair(score2, min2);
                        }
                        // Probably makes no difference
                        else if (score1 > score2){
                            dp[i][j] = make_pair(score1, min1);
                        }
                        else{
                            dp[i][j] = make_pair(score2, min2);
                        }
                    }
                }
            }
        */

        // However, this won't work, as there is an issue: if
        // at some point we can choose between (score: 10, min:-5)
        // and (score: 1, min:-1), our algorithm will choose the latter,
        // but if on the next turn, we get a square with value -10, 
        // having chosen the former would have been better.
        // So in order to "predict" if future squares will be negative and
        // need better score or positive/small negatives and need to priotitize
        // a lesser minimum, we start at the bottom, and each step calculate
        // only the minimum (no need for a pair of numbers). Each time we increase
        // or decrease the minimum by the score of the square. If the score is
        // positive and large enough to make the minimum positive, we only make it
        // 0. This is because the real travel direction is opposite, and while this
        // score is enough to "cushion" our here from the future negative squares,
        // it should have no effect on minimum he encounters "before", so for example,
        // if starting from the end, we currently have a minimum of -10, 
        // and reach a square 12, it's as if we don't have to worry about the
        // the -10, and are minimum needed value is 0, but not 2, because
        // if we choose 2, this will affect the minimum we may get later in the
        // search, which in relaity happens earlier, and shouldn't be cushioned
        // by later square scores.

        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = n-1; i >= 0 ; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1){
                    dp[i][j] = min(dungeon[i][j], 0);
                } else if (i == n-1){
                    dp[i][j] = min(dp[i][j+1] + dungeon[i][j], 0);
                } else if (j == m-1){
                    dp[i][j] = min(dp[i+1][j] + dungeon[i][j], 0);
                } else{
                    int min1 = min(dp[i+1][j] + dungeon[i][j], 0);
                    int min2 = min(dp[i][j+1] + dungeon[i][j], 0);

                    if(min1 > min2){
                        dp[i][j] = min1;
                    } else if (min1 <= min2){
                        dp[i][j] = min2;
                    }
                    // Probably makes no difference
                    else if (dp[i+1][j] > dp[i][j+1]){
                        dp[i][j] = min1;
                    }
                    else{
                        dp[i][j] = min2;
                    }
                }
            }
        }
        // The hero must have at least the minimal minimum health at the
        // start to survive + 1 (so he doesn't get to 0). If the minimal
        // health he can reach is positive, we just output 1.
        return (dp[0][0] < 0 ? -dp[0][0] + 1 : 1);
    }
};