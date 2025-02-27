/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/maximal-square/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    // Descirbes top left and bottom right square.
    struct Square{
        int x1, y1, x2, y2;

        int area(){
            if(isEmpty()) return 0;
            return (x2-x1 + 1) * (y2 - y1 + 1);
        }

        bool isEmpty(){
            return x1 == -1;
        }
    };

    int maximalSquare(vector<vector<char>>& matrix) {
        // We can use 2D dp grid.
        // Each entry in the grid is the largest area
        // square that has its bottom right corner
        // at said entry.
        // If the cell at matrix[i][j] is 0, then dp[i][i]
        // is an empty square.

        // Otherwise, if 1:
        // First we take dp[i-1][j] and dp[i][j-1], the largest
        // squares of the entry to the left and above the current
        // cell.
        // If either is an empty square, then dp[i][j] has size 1
        // (assuming now that the cell matrix[i][j] is '1').

        // The left boundary of the current largest square dp[i][j]
        // is at most that of dp[i][j-1], and the top boundary
        // is at most that of dp[i-1][j].
        // We get the top left cell which we will call (a, b).
        // if (a,b) to (i, j) is a square, we check to make sure
        // (a, b) is filled with 1: if it is, the square is from
        // (a, b) to (i, j).
        // If not filled, the square is from (a+1, b+1) to (i, j).
        // If (a, b) to (i, j) is not a square, we shrink the
        // longer side until it is.

        // When we are on the left or top boundary of the grid,
        // the largest square is at most of area 1.

        // Finally, we return the largest square element in dp.

        vector<vector<Square>> dp(
            matrix.size(), 
            vector<Square>(matrix[0].size())
        );

        int max = -1;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){

                if(matrix[i][j] == '0'){
                    dp[i][j] = Square(-1, -1, -1, -1);
                }
                else{
                    // Boundary
                    if(i == 0 || j == 0){
                        dp[i][j] = Square(j, i, j, i);
                    }
                    else{
                        // Two neighbors
                        Square s1 = dp[i-1][j];
                        Square s2 = dp[i][j-1];

                        if(s1.isEmpty() || s2.isEmpty()){
                            dp[i][j] = Square(j, i, j, i);
                        }
                        else{
                            // Cell (a, b) at boundary
                            int x = s2.x1;
                            int y = s1.y1;

                            // If it is a square
                            if(j - x == i - y){
                                if(matrix[y][x] == '1'){
                                    dp[i][j] = Square(x, y, j, i);
                                }
                                else{
                                    dp[i][j] = Square(x+1, y+1, j, i);
                                }
                            }
                            // Else we shrink it
                            else if (j - x > i - y){
                                // Since we want j - x == i - y
                                // we set x = y - i + j by just
                                // doing alegbra.
                                x = y - i + j;
                                dp[i][j] = Square(x, y, j, i);
                            }
                            else{
                                // Same for y.
                                y = x -j + i;
                                dp[i][j] = Square(x, y, j, i);
                            }
                        }
                    }       
                }

                // Then we check the max
                int area = dp[i][j].area();
                if(max < area){
                    max = area;
                }
            }
        }

        return max;
    }
};