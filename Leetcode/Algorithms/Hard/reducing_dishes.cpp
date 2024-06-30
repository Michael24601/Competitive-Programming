/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/reducing-dishes/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // It's clear we need to first sort the satisfactions
        // because larger satisfaction will clearly benefit from
        // being multiplied by a larger number later.
        // Then at each step we add a new number at the start of
        // the process (since the number is smaller than the others,
        // we multiply it by the smallest index, 1).
        // We stop once the process is no longer profitable 
        // (if the satisfaction is so negative the benefit of increasing
        // the factors of other satisfactions of adding it is no longer
        // worth it).
        // There is no need for dynamic programming here.

        int s = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0;
        for(int i = 0; i < s; i++){
            // If we are at 1a + 2b + 3c, we 
            // need the sum to become 1x + 2a + 3b + 4c
            // by adding the x. If the total sum is larger
            // we continue, else we stop.
            // This is the same as doing x + sum + a + b  c.
            int newSum = satisfaction[s - 1 - i] + sum;
            for(int j = 0; j < i; j++){
                newSum += satisfaction[s - 1 - j];
            }
            if (newSum >= sum) sum = newSum;
            else break;
        }
        return sum;
    }
};