/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/count-numbers-with-unique-digits/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {\

        if(n == 0) return 1;
        if(n == 1) return 10;

        // The pattern is really simple
        // dp[n] = dp[n-1] + 9 * (9 * 8 * 7 ... (9-n+1))
        // dp[1], the base case, is 10
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 10;

        for (int k = 2; k <= n; k++) {
            dp[k] = dp[k - 1];
            int product = 9;
            for (int i = 9; i > 9 - k + 1; i--) {
                product *= i;
            }
            dp[k] += product;
        }

        return dp[n];
    }
};