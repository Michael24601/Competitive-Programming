/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/path-with-maximum-probability/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(
        int n, vector<vector<int>>& edges, 
        vector<double>& succProb, 
        int start_node, int end_node
    ) {
        // This is just a normal dijkstra algorithm, but we want to maximize the
        // path length, and the length is calculated as a product, not a sum
        // (since we have probabilities).

        // Adjacency list
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            graph[u].emplace_back(v, prob);
            graph[v].emplace_back(u, prob);
        }
        
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;
        
        // Dijkstra
        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            if (node == end_node) {
                return prob;
            }
            
            for (auto& [neighbor, edgeProb] : graph[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }
        
        return 0.0; 
    }
};