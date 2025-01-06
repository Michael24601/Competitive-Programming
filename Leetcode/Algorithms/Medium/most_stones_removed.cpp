/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems//most-stones-removed-with-same-row-or-column/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {

    // Function to perform BFS on nodes, and marking visited nodes
    void bfs(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Exploring all neighbors of the current node
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    // Function to find all connected components in an undirected graph
    int findConnectedComponents(const vector<vector<int>>& adjList) {
        int n = adjList.size();
        vector<bool> visited(n, false);
        int connectedComponents = 0;
        
        // Loop through all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // If the node has not been visited,
                // it's the start of a new connected component.
                bfs(i, adjList, visited);
                // Incrementing the component count
                connectedComponents++;
            }
        }
        
        return connectedComponents;
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        // We can imagine the problem as an undirected graph
        // where an edge connects two stones if they are on
        // the same row or column. 
        // A conected component in the graph (nodes that can
        // be reached from each other) corresponds to a set
        // of stones, which, if removed in the "correct order"
        // can be removed entirely except for one stone.
        // So if we have for example 3 stones that form an
        // "L" shape, we can remove only 1 stone if we removed
        // the corner, but 2 stones if we remove one of the tails
        // first. Any connected component of n nodes can have
        // n-1 stones (nodes) removed.
        
        // So our goal is to find all connected components using
        // BFS, and returning the sum of their sizes minus 1 each,
        // which is also the number of stones - the number of
        // connected components.

        // Alternatively, we can think of turing the problem
        // into that of sets, where connected components are
        // disjoint sets.

        // map that stores all stones in each column and row
        unordered_map<int, vector<int>> rowMap;
        unordered_map<int, vector<int>> colMap;
        for(int i = 0; i < stones.size(); i++){
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }

        // We can then fill the adjacency list with 
        // stones that share the same row or column.
        // No need to worry that a stone will be added twice
        // since sharing a column means the stone can't share
        // the same row.
        vector<vector<int>> adjList(stones.size());
        for(int i = 0; i < stones.size(); i++){
            // For all stones in the same rowA
            for (int j : rowMap[stones[i][0]]) {
                // The stone isn't connected to itself
                if (i != j) {
                    adjList[i].push_back(j);
                }
            }

            // For all stones in the same column
            for (int j : colMap[stones[i][1]]) {
                if (i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        int connectedComponents = findConnectedComponents(adjList);
        return stones.size() - connectedComponents;
    }
};