
#include <bits/stdc++.h>

using namespace std;

// Kahn's algorithm can be used to topologically order the vertices of a
// a directed graph. This lets us basically order the nodes in such a
// way that for any two nodes i an j, j has to come after i if there is
// ever an edge that goes from j to i.

// This can work for any DAG (directed acyclic graph).
// THe algorithm works by first choosing a node that has no incoming
// edges, placing it first in the ordering, removing it from the graph
// (and its associated edges), and repeating, until all nodes are removed
// or we no longer have any nodes with no incoming edges; when that happens
// we know we've reached a cycle, so the algorithm fails.

// We can optimize this a bit by associating a degree n with all 
// nodes that is the number of incoming edges. We can remove all nodes
// wit degree 0, place them in topological order (doesn't matter how we
// order them), then decrement all nodes that has incoming edges from the
// removed nodes.

// We can use a queue to place nodes whose degree has turned to 0, 
// and each time we dequeue one, we can decrement the degree of its neighbors.

// In an adjacency matrix, we need one pass over the nodes first to set the
// initial degree, and then a second pass that edge by edge decrements the node
// degrees. So we pass over the edges and nodes a constant number of times,
// which makes the algorithm take O(V+E) time.

// In an adjacency matrix, we have to pass over all nodes for each node
// to set the degree of each node, and we also have to pass over all nodes
// to check if they have an incoming edge from the node we're currently on, so 
// the time is O(V^2);


// For adjacnency matrix
bool kahnAlgorithm(
    const vector<vector<bool>>& adjMatrix, vector<int>& topologicalOrdering
){

    // First pass to set the degrees of each node
    vector<int> degree(adjMatrix.size());
    for (int i = 0; i < adjMatrix.size(); i++) {
        for (int j = 0; j < adjMatrix[i].size(); j++) {
            if(adjMatrix[i][j]){
                degree[j]++;
            }
        }
    }

    queue<int> q;
    // We intially store all nodes with 0 degrees
    for(int i = 0; i < degree.size(); i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    // When the queue is empty either the graph is done
    // or a cycle is reached.
    while(!q.empty()){
        // Pop a node, place it in the topological order,
        // and then decrement the neighbors.
        int node = q.front();
        topologicalOrdering.push_back(node);
        for(int i = 0; i < adjMatrix[node].size(); i++){
            if(adjMatrix[node][i]){
                degree[i]--;
                if(degree[i] == 0){
                    q.push(i);
                }
            }
        }
        q.pop();
    }

    return topologicalOrdering.size() == adjMatrix.size();
}


// For adjacency list
bool kahnAlgorithm(
    const vector<vector<int>>& adjList, vector<int>& topologicalOrdering
){

    // First pass to set the degrees of each node
    vector<int> degree(adjList.size());
    for (int i = 0; i < adjList.size(); i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            degree[adjList[i][j]]++;
        }
    }

    queue<int> q;
    // We intially store all nodes with 0 degrees
    for(int i = 0; i < degree.size(); i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    // When the queue is empty either the graph is done
    // or a cycle is reached.
    while(!q.empty()){
        // Pop a node, place it in the topological order,
        // and then decrement the neighbors.
        int node = q.front();
        topologicalOrdering.push_back(node);
        for(int i = 0; i < adjList[node].size(); i++){
            int index = adjList[node][i];
            degree[index]--;
            if(degree[index] == 0){
                q.push(index);
            }
        }
        q.pop();
    }

    return topologicalOrdering.size() == adjList.size();
}
