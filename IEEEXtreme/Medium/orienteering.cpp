/*
    Website: IEEEXtreme
    Difficulty: Medium
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/95352fd33b0e855d337b5b3ed85da3b6/
*/


#include <bits/stdc++.h>

using namespace std;

float pathTime(int i, int j, int k, int l, 
    const vector<vector<float>>& r,  const vector<vector<float>>& e) {
    float t = ((r[i][j] + r[k][l])/2.0 )
    * exp(3.5 * abs(((e[k][l] - e[i][j])/10.0) + 0.05));
    return t;
}

// Shortest path using djikstra (with an adjacency list, not matrix)
float shortestPathDijkstra(const vector<vector<pair<int, float>>>& adjacencyList, 
    int A, int B) {

    int n = adjacencyList.size();
    vector<float> distance(n, numeric_limits<float>::max());
    priority_queue<pair<float, int>, vector<pair<float, int>>, 
    greater<pair<float, int>>> pq;
    distance[A] = 0;
    pq.push({0, A});

    while (!pq.empty()) {
        int u = pq.top().second;
        float dist_u = pq.top().first;
        pq.pop();

        if (u == B) {
            return dist_u;
        }

        for (const auto& edge : adjacencyList[u]) {
            int v = edge.first;
            float weight = edge.second;
            if (dist_u + weight < distance[v]) {
                distance[v] = dist_u + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return -1;
}

int main() {
    // What we can do is build a graph of the entire map, where each square
    // is a node connected to the four surrounding it, with a path the specified
    // length (using the formula).
    // We then use djikstra between each 2 control points.
    // According to the problem statement we can cross the same square more
    // once. This is because we will run djikstra between different pairs of nodes,
    // so while we never repeat ourselves when using the algorithm once,
    // it is inevitable when running independent instances of it.
    int n, m, p;
    cin >> n >> m >> p;
    
    // Path is saved in the format i*m + j, which will make sense later
    vector<int> path(p+1);
    for(int k = 0; k < p+1; k++){
        int i, j;
        cin >> i >> j;
        path[k] = i*m + j;
    }
    
    vector<vector<float>> runnability(n, vector<float>(m, 0));
    vector<vector<float>> elevation(n, vector<float>(m, 0));
    
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            cin >> runnability[i][j];
        }
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            cin >> elevation[i][j];
        }
    }
    
    // Instead of using an adjacency matrix, we can use an adjacency list,
    // which is slower but uses less memeory, since out graph is very sparse
    // (only 4 connections from any node). This is the trick of this exercise,
    // using the less often seen data structure to store the graph, since 
    // the graph is obviously quite sparse.
   vector<vector<pair<int, float>>> adjacencyList(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0)
                adjacencyList[i * m + j].emplace_back(
                    (i - 1) * m + j, pathTime(i, j, i - 1, j, runnability, elevation));
            if (i + 1 < n)
                adjacencyList[i * m + j].emplace_back(
                    (i + 1) * m + j, pathTime(i, j, i + 1, j, runnability, elevation));
            if (j - 1 >= 0)
                adjacencyList[i * m + j].emplace_back(
                    i * m + (j - 1), pathTime(i, j, i, j - 1, runnability, elevation));
            if (j + 1 < m)
                adjacencyList[i * m + j].emplace_back(
                    i * m + (j + 1), pathTime(i, j, i, j + 1, runnability, elevation));
        }
    }
        
        
    float totalPath{};
    for(int i = 0; i < path.size()-1; i++){
        float distance 
            = shortestPathDijkstra(adjacencyList, path[i], path[i+1]);
        totalPath += distance;
    }
    
    cout << ceil(totalPath);
    
    return 0;
}