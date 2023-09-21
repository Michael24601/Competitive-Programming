/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/two-pluses/problem
*/


#include <bits/stdc++.h>

using namespace std;

struct p {
    int y;
    int x;
};

// Returns all two lines of a crossing starting with bottom to top,
// then left to right
vector<pair<pair<p, p>, pair<p, p>>> getCrossings(vector<vector<bool>>& grid) {
    vector<pair<pair<p, p>, pair<p, p>>> crossings;
    int r = grid.size(), c = grid[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
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

// Return sum of cross
int getArea(pair<pair<p, p>, pair<p, p>>& cross) {
    return (cross.second.second.x - cross.second.first.x) * 2 + 1;
}

// Checks if two crosses intersect
bool areIntersecting(pair<pair<p, p>, pair<p, p>>& cross1,
    pair<pair<p, p>, pair<p, p>>& cross2) {
    int centerX1 = cross1.first.first.x;
    int centerX2 = cross2.first.first.x;
    int centerY1 = cross1.second.first.y;
    int centerY2 = cross2.second.first.y;

    // Horizontal1 and Vertical2
    if (centerY2 >= cross1.first.first.y && centerY2 <= cross1.first.second.y &&
        centerX1 >= cross2.second.first.x && centerX1 <= cross2.second.second.x) {
        return true;
    }
    
    // Horizontal2 and Vertical1
    if (centerY1 >= cross2.first.first.y && centerY1 <= cross2.first.second.y &&
        centerX2 >= cross1.second.first.x && centerX2 <= cross1.second.second.x) {
        return true;
    }
    
    // Vertical1 and Vertical2
    if (centerX2 == centerX1) {
        if(centerY2 == centerY1)
            return true;
        else if (centerY2 > centerY1 
        && cross2.first.first.y <= cross1.first.second.y){
            return true;
        }
        else if (centerY1 > centerY2 
        && cross1.first.first.y <= cross2.first.second.y){
            return true;
        }
    }

    // Horizontal1 and Horizontal2
    if (centerY2 == centerY1){
        if(centerX2 == centerX1)
            return true;
        else if (centerX2 > centerX1 
        && cross2.first.first.x <= cross1.first.second.x){
            return true;
        }
        else if (centerX1 > centerX2 
        && cross1.second.first.x <= cross2.second.second.x){
            return true;
        }
    }

    return false;
}

// Because the inputs are so small, we will use brute force
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> grid(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = (c == 'G');
        }
    }
    
    vector<pair<pair<p, p>, pair<p, p>>> crossings = getCrossings(grid);

    int max = -1;
    for (int i = 0; i < crossings.size(); i++) {
        for (int j = 0; j < crossings.size(); j++) {
            if (!areIntersecting(crossings[i], crossings[j])) {
                int s = getArea(crossings[i]) * getArea(crossings[j]);
                if (s > max) {
                       max = s;
                }
            }
        }
    }

    cout << max;

    return 0;
}
