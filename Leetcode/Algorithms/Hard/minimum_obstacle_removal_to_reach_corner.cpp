/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> shortestPathDijkstraList(
        const vector<vector<pair<int, int>>>& adjacencyList, 
        int source, int destination
    ) {

        int n = adjacencyList.size();
        vector<int> distance(n, numeric_limits<int>::max());
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        
        distance[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            
            for (const pair<int, int>& edge : adjacencyList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (!visited[v]) {
                    int alt = distance[u] + weight;
                    if (alt < distance[v]) {
                        distance[v] = alt;
                        parent[v] = u;
                        pq.push({distance[v], v});
                    }
                }
            }
        }
        
        // Reconstructing the shortest path
        vector<int> path;
        int current = destination;
        while (current != -1) {
            path.push_back(current);
            std::cout << current << "\n";
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        // If we think of squares as nodes and edges as connecting
        // squares to the right, left, top, and bottom squares,
        // this is no more than djikstra where the edges can have
        // length 1 (obstacle) or 0 (no obstacle).
        // If I go to any square with an obstacle (from any square),
        // the path is a 1.
        // If so, the shortest path is the number of obstacles
        // to remove.

         // Adjacency list
        int rowSize = grid[0].size();
        int n = rowSize * grid.size();
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < rowSize; j++){
                if(i > 0){
                    graph[i * rowSize + j].push_back(
                        make_pair((i-1) * rowSize + j, grid[i-1][j])
                    );
                }
                if(j > 0){
                    graph[i * rowSize + j].push_back(
                        make_pair(i * rowSize + (j-1), grid[i][j-1])
                    );
                }
                if(i < grid.size() - 1){
                    graph[i * rowSize + j].push_back(
                        make_pair((i+1) * rowSize + j, grid[i+1][j])
                    );
                }
                if(j < rowSize - 1){
                    graph[i * rowSize + j].push_back(
                        make_pair(i * rowSize + (j+1), grid[i][j+1])
                    );
                }
            }
        }

        // Top left
        int start_node = 0;
        // Bottom right
        int end_node = rowSize * grid.size() - 1;
        
        vector<int> path = shortestPathDijkstraList(graph, start_node, end_node);
        int sum = 0;
        for(int i = 0; i < path.size(); i++){
            sum += grid[path[i] / rowSize][path[i] % rowSize];
        }

        return sum;
    }
};