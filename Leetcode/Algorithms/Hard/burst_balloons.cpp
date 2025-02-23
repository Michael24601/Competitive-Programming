/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/burst-balloons/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Suppose we have A1, A2, A3 ... An matrices
        // and we want to calculate the product:
        // A1 * A2 * A3 ... An.
        // Though the solution does not depend on the order,
        // the time compelxity does. The time it takes
        // to calculate Ai * Aj is rows_i * cols_i * cols_j.
        // (Assuming cols_i = rows_j).

        // The way to find the optimal ordering is this:
        // We have to split the matrices somewhere such that
        // we have (A1 * A2 * ... Ak) * (Ak+1 * ... An).
        // There are n-1 such splits we can do.
        // We just choose the optimal split,
        // then compute the time it takes to do each split,
        // which is the optimal time it takes to solve the
        // subproblems (A1 ... Ak) and (Ak+1 ... An)
        // plus the time it takes to multiply their results:
        // P(i, j) = min[for k=i to k=j-1]{ 
        //     P(i, k) + P(k+1, j) + rows_i * cols_k * cols_j
        // }
        // where rows_i * cols_k * cols_j is the cost of multiplying
        // the resulting matrices from the split (first chain starts
        // at Ai and ends at Ak, so it will have rows same as Ai
        // and columns same as Ak, second matrix will have the rows
        // of Ak+1 and the columns of Aj since it ends at Aj).

        // This takes exponential time to solve O(2^n).
        // However, the number of subproblems P(i, j)
        // where 1 <= i <= j <= n is C(n, 2) = O(n^2)
        // (top half of a 2D grid). So if we use memoization
        // to avoid computing an already solved subproblem,
        // by storing P(i, j) in a grid, we can solve the algorithm
        // in O(n^3) time (each cells takes n time, since we have
        // to calculate the minimum).

        // We know that P(i, i) = 0 since we only have one matrix,
        // so we can use it as a base case, and solve the table one
        // diagonal at a time (corresponding each time to one more
        // added matrix, from 1, to 2, ... to n).
        // We only have to solve one half of the table since i <= j.

        // Now, notice that the baloon problem is very similar:
        // Like the matrix ordering, the "points" we get is
        // nums[i - 1] * nums[i] * nums[i + 1], which is similar
        // to rows_i * cols_i * cols_j. 
        // We can do the exact same algorithm if, for baloons
        // [b1, b2, b3],
        // We create the matrices
        // [(1, b1), (b1, b2), (b2, b3), (b3, 1)]
        // This is because bursting baloons b2 leaves [b1, b3],
        // which is the same as multiplying matrices 
        // (b1, b2), (b2, b3), and leaving matrix (b1, b3)
        // in its place.
        // The 1s are for padding.
        // The only difference is we want the max, not min.

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // Matrix array
        vector<pair<int, int>> matrices(nums.size() - 1);
        for(int i = 0; i < nums.size() - 1; i++){
            matrices[i] = make_pair(nums[i], nums[i+1]);
        }

        int n = matrices.size();

        // Dp grid
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // D for diagonal (we explore diagonal by diagonal)
        // to ensure the grid fills in order.
        for(int d = 1; d < n; d++){
            // i for row
            for(int i = 0; i < n-d; i++){
                // j for column
                int j = i + d; 

                int max = -1;

                // The range of numbers that k can have can go
                // from i to j (which baloon to burst between i and j).
                for(int k = i; k < j; k++){

                    // This is P(i, j) split at k
                    int value = matrices[i].first * matrices[k].second
                        * matrices[j].second
                        + dp[i][k]
                        + dp[k+1][j];
            
                    if(value > max){
                        max = value;
                    }     
                }

                dp[i][j] = max;
            }
        }

        return dp[0][n-1];
    }
};