
/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/palindrome-partitioning/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // This function uses backtracking to search the
    // dp array, starting at the given palindrome
    // which starts at the given start index,
    // returns all the ways we can reach the end
    // by traversing using palindromes that start
    // at the point the current palindrome ends.
    // The traversal is recorder as the start of each
    // substring.
    void backtrack(
        int start, const vector<vector<bool>>& dp,
        vector<vector<int>>& traversals,
        // The current path
        vector<int>& currentPath
    ){

        // We've reached the end, so we have a valid partition
        if(start == dp.size()){
            // We can add the current path to the traversals
            // as it is a success
            traversals.push_back(currentPath);
            return;
        }

        currentPath.push_back(start);

        // Otherwise, we need to go to the next substring
        for(int i = start; i < dp.size(); i++){
            // If the substring is a palindrome
            if(dp[start][i]){
                backtrack(i+1, dp, traversals, currentPath);
            }
        }
        
        currentPath.pop_back();
    }

    vector<vector<string>> partition(string s) {
        // In this 2D array, we can have entry(i, j)
        // be true if the substring starting at i and
        // ending at j is a palindrome.
        // We can use the solution of smaller substrings
        // to solve those of larger ones

        // Instead of starting at [0][0] and ending at 
        // [size-1][size-1], we start with all palidnromes
        // of size 1, then 2, etc...
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int size = 1; size <= s.size(); size++){
            // j is the start variable
            for(int j = 0; j < s.size() - size + 1; j++){

                int end = j + size - 1;

                // Base case size = 1
                if(size == 1) {
                    dp[j][end] = true;
                }
                // Base case size == 2
                else if(size == 2){
                    if(s[j] == s[j+1]){
                        dp[j][j+1] = true;
                    }
                }
                else{
                    // For a string starting at i
                    // and ending at j,
                    // we can just check if s[start] == s[end],
                    // and if the string starting at [start+1]
                    // and ending at [end-1] is a palindrome
                    if(s[j] == s[end] && dp[j+1][end-1]){
                        dp[j][end] = true;
                    }
                }
            }
        }  

        // We now need to do a DFS of the array in this way:
        // We start with a palindrome that starts at i = 0,
        // and then we see where it ends. If it ends at j,
        // we check to find a palindrome that starts at j+1.
        // We continue doing this, and if we reach the end,
        // partition is correct, else it is not. At each step
        // we do a depth first search, where we choose one of
        // the palindromes that start with j+1 one by one.
        // We can do this easily using backtracking.
        
        vector<vector<int>> traversals;
        vector<int> current{};
        backtrack(0, dp, traversals, current);

        // The traversal but as a string
        vector<vector<string>> traversalStrings(traversals.size());

        for(int i = 0; i < traversals.size(); i++){
            for(int j = 0; j < traversals[i].size(); j++){
                
                int start = traversals[i][j];
                int length; 
                if(j != traversals[i].size() - 1){
                    length = traversals[i][j+1] - traversals[i][j];
                }

                if(j != traversals[i].size() -1){
                    traversalStrings[i].push_back(s.substr(start, length));
                }
                else{
                    traversalStrings[i].push_back(s.substr(start));
                }
            }
        }

        return traversalStrings;
    }
};