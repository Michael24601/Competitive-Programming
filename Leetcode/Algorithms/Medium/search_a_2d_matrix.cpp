/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/search-a-2d-matrix/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Returns entry from 2D matrix given a 1D index
    int returnEntry(vector<vector<int>>& matrix, int index){

        int n = index / matrix[0].size();
        int m = index % matrix[0].size();
        
        return matrix[n][m];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Since each row's entries are smaller than the last row's,
        // and all rows are sorted, we can treat the matrix as a 1D
        // array and just use binary search.

        int n = matrix.size(), m = matrix[0].size();
        int start = 0;
        int end =  n*m - 1;

        while(end >= start){
            int mid = (end + start)/2;
            int midVal = returnEntry(matrix, mid);
            if(midVal < target){
                start = mid + 1;
            }
            else if(midVal > target){
                end = mid - 1;
            }
            else{
                return true;
            }
        }

        return false;

    }
};