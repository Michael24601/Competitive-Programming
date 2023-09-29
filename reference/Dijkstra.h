#include <bits/stdc++.h>

using namespace std;


// We can use Dijkstra with an adjacecny list (we build a 2D matrix of
// dimension n * n for n nodes where m[i][j] is the distance from node i to
// node j. If the entry is 0 we assume there is no path).
// We can also use an adjacency list, where each node in the vector is
// followed by a linked list of nodes it's connected to, each with an
// index and distance for the node it's connected to and the distance to it.
// The first approach is faster, as there is no need to loop over the nodes
// (retrieval is O(1)), but for a sparse graph, the second option is better.
// The first would waste too much unnecessary space. The second only
// allocates space for needed edges, and the speed isn't an issue as
// the sparceness of the graph means there aren't too many edges to loop over
// for each node.
// Note that Dijkstra only works for distances that are positive, because
// it assumes we must never enter into cycles. When the distances are positive,
// we can always assume that if we reach a node from the shortest distance
// up to this point with the shortest path to it, that total path is the
// shortest distance from the source to the node. This isn't necessarily
// true if there are neagtive distances, where repeating cycles can lead to
// less of a cost (distance).

// Djikstra algorithm that takes an adjacecny matrix
vector<int> shortestPathDijkstraMatrix(
    const vector<vector<int>>& adjacencyMatrix, 
    int source, int destination) {
    int n = adjacencyMatrix.size();
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
        
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && adjacencyMatrix[u][v] > 0) {
                int alt = distance[u] + adjacencyMatrix[u][v];
                if (alt < distance[v]) {
                    distance[v] = alt;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
    }
    
    // Reconstruct the shortest path
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    
    reverse(path.begin(), path.end());

    // We can return the path as a vector of indeces,
    // or we can return the shortest distance (distance[destination]),
    // which is the shortest distance for any node in the shortest path vector.
    return path;
}

vector<int> shortestPathDijkstraList(
    const vector<vector<pair<int, int>>>& adjacencyList, 
    int source, int destination) {

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
    
    // Reconstruct the shortest path
    vector<int> path;
    int current = destination;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    
    // We can return the path as a vector of indeces,
    // or we can return the shortest distance (distance[destination]),
    // which is the shortest distance for any node in the shortest path vector.
    reverse(path.begin(), path.end());
    return path;
}

// Now, if we want ALL possible shortest paths (if there are multiple
// ones with the same length), we can return the distance in the above
// functions instead of the paths, and then use the following functions

void findAllPathsDFS(const vector<vector<long long>>& graph, 
    long long current, long long destination, long long distance, 
    vector<bool>& visited, vector<long long>& currentPath, 
    vector<vector<long long>>& allPaths) {
        
    visited[current] = true;
    currentPath.push_back(current);

    if (current == destination && distance == 0) {
        allPaths.push_back(currentPath);
    } else {
        for (long long neighbor = 0; neighbor < graph.size(); ++neighbor) {
            if (!visited[neighbor] && graph[current][neighbor] > 0 
                && distance >= graph[current][neighbor]) {
                findAllPathsDFS(graph, neighbor, destination, 
                distance - graph[current][neighbor], 
                visited, currentPath, allPaths);
            }
        }
    }

    visited[current] = false;
    currentPath.pop_back();
}

// Send teh function the adjacency matrix, the source, destination, and
// the shortest distance (or any distance we want the path to be).
vector<vector<long long>> findPathsGivenDistance(
    const vector<vector<long long>>& adjacencyMatrix, long long source, 
    long long destination, long long distance) {
        
    long long n = adjacencyMatrix.size();
    vector<vector<long long>> allPaths;
    vector<long long> currentPath;
    vector<bool> visited(n, false);

    findAllPathsDFS(adjacencyMatrix, source, destination, 
        distance, visited, currentPath, allPaths);

    return allPaths;
}