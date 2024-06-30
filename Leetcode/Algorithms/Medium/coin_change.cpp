/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/coin-change/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // We can use dynamic programming to solve this.
        // Basically, suppose p(m) is the smallest number of coins
        // that makes up a value m if we have coins a, b, and c.
        // Then to get p(n), what we can do
        // is find min(p(n-a), p(n-b), p(n-c)) + 1. This is because
        // we can add a, b, or c to any optimal solution alrrady found
        // to get p(n), we just need the smallest optimal solution of
        // a previous number.
        // It is however possible that not all numbers can be made with
        // the coins we have, which will happen when we don't have the 1
        // coin.
        // If n can't be formed, we put p(n) = infinity.
        // The way we know p(mn) can't be summed is if, when we
        // write min(p(n-a), p(n-b), p(n-c)),
        // none of p(n-a), p(n-b), p(n-c) exist, either because
        // n-a, n-b, n-c are all negative numbers,
        // or because p(n-a), p(n-b), p(n-c) are also infinite
        // (impossible to make). Note that we chose infinity here
        // because when compared with any other number, we take
        // the other number (so if only one of the antecedants exist,
        // we choose that one).
        // If p(amount) is infinity, we return -1.
        // The base case is p(0) = 0.

        constexpr int INF = std::numeric_limits<int>::max();

        std::vector<int> p(amount+1);
        p[0] = 0;
        for( int i = 1; i < p.size(); i++){
            // Smallest antecedant
            int min = INF;
            for(int j = 0; j < coins.size(); j++) {
                // If (n-a isn't negative)
                if(i - coins[j] >= 0){
                    // Standard minimum algorithm
                    if(p[i - coins[j]] < min){
                        min = p[i - coins[j]];
                    }
                }
            }
            // If the minimum is infinity, then either all the antecedants
            // are negative, or all the existing ones are infinity, so 
            // this number has no solution
            if(min == INF) p[i] = INF;
            else p[i] = min + 1;
        }
        if(p[p.size() - 1] == INF) return -1;
        else return p[p.size() - 1];
    }
};