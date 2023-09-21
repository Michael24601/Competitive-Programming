#include <bits/stdc++.h>

using namespace std;

struct p {
    int x;
    int y;
};

// Returns all two lines of a crossing starting with bottom to top,
// then left to right
vector<pair<pair<p, p>, pair<p, p>>> getCrossings(vector<vector<bool>>& grid) {
    vector<pair<pair<p, p>, pair<p, p>>> crossings;
    int r = grid.size(), c = grid[0].size();
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            // Check for all crossings centered here
            if (grid[i][j]) {
                crossings.push_back(pair<pair<p, p>, pair<p, p>>(
                    pair<p, p>(p{i, j}, p{i, j}), pair<p, p>(p{i, j}, p
                    {i, j})));
            }
            // plus size
            int n = 1;
            while (n < min(r, c)) {
                // Once we reach a border, or hit a false square, we can stop
                // looking for a bigger +, since all else will fail.
                if (i - n < 0 || !grid[i - n][j]) {
                    break;
                }
                if (i + n >= r || !grid[i + n][j]) {
                    break;
                }
                if (j - n < 0 || !grid[i][j - n]) {
                    break;
                }
                if (j + n >= c || !grid[i][j + n]) {
                    break;
                }
                crossings.push_back(pair<pair<p, p>, pair<p, p>>(
                    pair<p, p>(p{i - n, j}, p{i + n, j}), pair<p, p>
                    (p{i, j - n}, p{i, j + n})));
                n++;
            }
        }
    }
    return crossings;
}

// Checks if two crosses intersect
bool areIntersecting(pair<pair<p, p>, pair<p, p>>& cross1,
                     pair<pair<p, p>, pair<p, p>>& cross2) {
    int centerX1 = cross1.first.first.x;
    int centerX2 = cross2.first.first.x;
    int centerY1 = cross1.second.first.y;
    int centerY2 = cross2.second.first.y;

    if (centerX2 >= cross2.second.first.x && centerX2 <= cross1.second.second.x &&
        centerY2 >= cross2.first.first.y && centerY2 <= cross1.first.second.y) {
        return false;
    }

    if (centerX2 == centerX1 &&
        centerY2 >= cross2.first.first.y && centerY2 <= cross1.first.second.y) {
        return false;
    }

    if (centerY2 == centerY1 &&
        centerX2 >= cross2.second.first.x && centerX2 <= cross1.second.second.x) {
        return false;
    }

    return true;
}

// Return sum of cross
int sum(pair<pair<p, p>, pair<p, p>>& cross) {
    return (cross.first.second.y - cross.first.first.y) * 2 - 1;
}

// Because the inputs are so small, we will use brute force
int main() {
    int n, m;
    cin >> n >> m;

    cout << n << " " << m << "\n";

    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            cout << c << " ";
            if (c == 'G')  // Corrected input character comparison
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }
        cout << i << " ";
    }
    
    cout << "a";
    
    vector<pair<pair<p, p>, pair<p, p>>> crossings = getCrossings(grid);

    int max = -1;  // Initialize max
    for (int i = 0; i < crossings.size(); i++) {
        for (int j = i + 1; j < crossings.size(); j++) {
            if (!areIntersecting(crossings[i], crossings[j])) {
                int s = sum(crossings[i]) + sum(crossings[j]);
                if (s > max) {
                    max = s;
                }
            }
        }
    }

    cout << max;

    return 0;
}