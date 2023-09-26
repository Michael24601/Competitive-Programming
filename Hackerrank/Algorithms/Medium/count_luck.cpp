/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/count-luck/problem
*/


#include <bits/stdc++.h>

using namespace std;

struct coordinate{
    int row;
    int column;
};

bool operator==(const coordinate& lhs, const coordinate& rhs) {
    return lhs.row == rhs.row && lhs.column == rhs.column;
}

bool operator!=(const coordinate& lhs, const coordinate& rhs) {
    return lhs.row != rhs.row || lhs.column != rhs.column;
}


// Takes the current location as well as the past positions we've visited,
// so we never visit a position more than once on any one coordinate (though
// different coordinates may corss the same coordinate).
// Note that we know that the right path is unique.
vector<coordinate> travel (vector<coordinate> last, coordinate current, 
    vector<vector<char>>& grid){
    
    int i = current.row, j = current.column;
    last.push_back({i, j});
    
    if(grid[i][j] == '*'){
        return vector<coordinate>(1, {i, j});
    }

    if(i-1 >= 0 && grid[i-1][j] != 'X'){
        if(find(last.begin(), last.end(), coordinate{i-1, j}) == last.end()){
            vector<coordinate> p = travel(last, coordinate{i-1, j}, grid);
            if(p.size() > 0){
                p.push_back({i, j});
                return p;
            }
        }
    }
    if(i+1 < grid.size() && grid[i+1][j] != 'X'){
        if(find(last.begin(), last.end(), coordinate{i+1, j}) == last.end()){
            vector<coordinate> p = travel(last, coordinate{i+1, j}, grid);
            if(p.size() > 0){
                p.push_back({i, j});
                return p;
            }
        }

    }
    if(j-1 >= 0 && grid[i][j-1] != 'X'){
        if(find(last.begin(), last.end(), coordinate{i, j-1}) == last.end()){
            vector<coordinate> p = travel(last, coordinate{i, j-1}, grid);
            if(p.size() > 0){
                p.push_back({i, j});
                return p;
            }
        }
    }
    if(j+1 < grid[0].size() && grid[i][j+1] != 'X'){
        if(find(last.begin(), last.end(), coordinate{i, j+1}) == last.end()){
            vector<coordinate> p = travel(last, coordinate{i, j+1}, grid);
            if(p.size() > 0){
                p.push_back({i, j});
                return p;
            }
        }
    }
    
    // If at this point, no coordinate returns anything,
    // we return an empty vector
    return vector<coordinate>();
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        
        coordinate start;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
                if(grid[i][j] == 'M'){
                    start = {i, j};
                }
            }
        }
        int k;
        cin >> k;
        vector<coordinate> empty;
        // We then reverse it since it's given in reverse
        vector<coordinate> path = travel(empty, start, grid);
        reverse(path.begin(), path.end());
        
        int count{};
        
        // Then at each path coordinate, if we have more than one
        // possible path (barring the path we came from, unless
        // we're at the start of the path), we consider
        // that a guess, we get their count, and comapre with k.
        // We also don't care once we reach the destination so
        // we stop the loop shy of * (even if paths branch from there)
        for(int i = 0; i < path.size() - 1; i++){
            int r = path[i].row, c = path[i].column;
            int available{};
            if(r-1 >= 0 && grid[r-1][c] != 'X' 
                && (i == 0 || (coordinate{r-1, c} != path[i-1]))){
                available++;        
            }
            if(r+1 < n && grid[r+1][c] != 'X' 
                && (i == 0 || (coordinate{r+1, c} != path[i-1]))){
                available++;        
            }
            if(c-1 >= 0 && grid[r][c-1] != 'X' 
                && (i == 0 || (coordinate{r, c-1} != path[i-1]))){
                available++;        
            }
            if(c+1 < m && grid[r][c+1] != 'X' 
                && (i == 0 || (coordinate{r, c+1} != path[i-1]))){
                available++;        
            }
            
            if(available > 1){
                count++;
            }
        }
        
        if(count == k){
            cout << "Impressed\n";
        }
        else{
            cout << "Oops!\n";
        }
    }
    
    return 0;
}
