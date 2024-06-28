/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/triangle/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // One solution to this problem is to update the triangle such that
        // each value now represents the shortest path to it from the top.
        // This can be done iteratively each line: For example, the first line  
        // has just one number, so we update the two numbers on the next line
        // to be the sum along with that number. Then for the third line, the
        // side number have only one option for their sum, but the middle
        // number has 2. Since the numbers that came before represent the total
        // sum at this point, and not just the value of the number on that line,
        // we can be sure the smaller of the two will always yield the shorter
        // path, so we use it to sum with the middle number. We repeat this for
        // all lines.

        // Starting from the second line
        for(int i = 1; i < triangle.size(); i++){
            for (int j = 0; j < triangle[i].size(); j++){
                // If one left side, we only have one sum option
                if(j == 0) triangle[i][j] += triangle[i-1][j];
                // Same for the right side number
                else if(j == i) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }

        // Then we return the minimum value of the last line for the
        // shortest path sum.
        int s = triangle.size() - 1;
        return *std::min_element(triangle[s].begin(), triangle[s].end());
    }
};