/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // The strategy is to store possible paths from node to node (entry
    // to entry) in an adjacency list (we only create a path to an entry j from
    // i if entry i is smaller than entry j), and then find the longest path
    // from any two nodes with depth first search. Note that to speed up the
    // process, we can save in a memoization table the longest path starting
    // from a node.

    unordered_map<int, int> memo;

    int dfs(int node, vector<vector<int>>& adj) {
        if (memo.find(node) != memo.end()) {
            return memo[node];
        }

        int longestPath = 0;
        for (int neighbor : adj[node]) {
            int pathLength = dfs(neighbor, adj);
            longestPath = max(longestPath, pathLength);
        }

        memo[node] = longestPath + 1;
        return memo[node];
    }

    int findLongestPath(vector<vector<int>>& adj) {
        int longestPath = 0;
        int n = adj.size();

        for (int i = 0; i < n; ++i) {
            int pathLength = dfs(i, adj);
            longestPath = max(longestPath, pathLength);
        }

        return longestPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> adj(n*m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i > 0 && matrix[i-1][j] > matrix[i][j]){
                    adj[i * m + j].push_back((i-1) * m + j);
                }
                if(j > 0 && matrix[i][j-1] > matrix[i][j]){
                    adj[i * m + j].push_back(i * m + j-1);
                }
                if(i < n-1 && matrix[i+1][j] > matrix[i][j]){
                    adj[i * m + j].push_back((i+1) * m + j);
                }
                if(j < m-1 && matrix[i][j+1] > matrix[i][j]){
                    adj[i * m + j].push_back(i * m + j+1);
                }
            }
        }

        return findLongestPath(adj);
    }
};