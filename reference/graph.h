
#include <bits/stdc++.h>

using namespace std;

// Graph algorithms

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


// Function to perform BFS on a start node, and return the component
// it is in.
void bfs(
    int start, const vector<vector<int>>& adjList,
    vector<int>& component,
    vector<bool>& visited
) {
    queue<int> q;
    q.push(start);
    component.push_back(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        // Exploring all neighbors of the current node
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                component.push_back(neighbor);
            }
        }
    }
}


// Function to find all connected components in an undirected graph,
// and returns the components
vector<vector<int>> findConnectedComponents(
    const vector<vector<int>>& adjList
) {
    int n = adjList.size();
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    int maxSize = 0;
    int maxIndex;
    
    // Loop through all nodes that are infected
    for (int i = 0; i < adjList.size(); i++) {
        if (!visited[i]) {
            // If the node has not been visited,
            // it's the start of a new connected component.
            vector<int> component;
            bfs(i, adjList, component, visited);
            components.push_back(component);
        }
    }
    
    return components;
}