
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

// Modfied Djikstra that can consider 0 paths as valid paths
int dijkstra(vector<vector<pair<int, int>>>& graph, 
    int startIndex, int endIndex) {

    int n = graph.size();
    vector<int> dist(n, INF);
    dist[startIndex] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startIndex});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == endIndex) {
            return d;
        }

        if (dist[u] < d) {
            continue;
        }

        for (const pair<int, int>& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return -1; // No path found
}

int main() {

    int ROWS, COLS, q;
    cin >> ROWS >> COLS >> q;

    vector<string> grid(ROWS);
    for(int i = 0; i < ROWS; i++){
        cin >> grid[i];
    }

    vector<vector<pair<int, int>>> adjacencyList(ROWS * COLS);

    // Define directions (8 possible moves)
    const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLS; ++x) {
            // For each cell, connect it to its neighbors with either 0 or 1 cost
            for (int dir = 0; dir < 8; ++dir) {
                int newX = x + dx[dir];
                int newY = y + dy[dir];

                // Check if the neighbor is within bounds
                if (newY >= 0 && newY < ROWS && newX >= 0 && newX < COLS) {

                    int currentCell = y * COLS + x;
                    int neighborCell = newY* COLS + newX;

                    // Determine the cost based on the cell value (O or ~)
                    int cost = (grid[y][x] == '~' && grid[newY][newX] == 'O') ? 1 : 0;

                    // Add the neighbor with the corresponding cost
                    adjacencyList[currentCell].emplace_back(neighborCell, cost);
                }
            }
        }
    }

    while(q--){

        int startY, startX, endY, endX;
        cin >> startY >> startX >> endY >> endX;

        int startIndex = (startY-1) * COLS + (startX-1);
        int endIndex = (endY-1) * COLS + (endX-1);

        cout << dijkstra(adjacencyList, startIndex, endIndex) << "\n";
    }

    return 0;
}