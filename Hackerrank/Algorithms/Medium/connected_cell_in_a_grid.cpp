/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
*/


#include <bits/stdc++.h>

using namespace std;

// Convert region

struct cell{
    int content;
    int region;
};

// Turns all elements in a region in a grid into elements of another
// region. Used when two disconnected regions are suddenly connected
// later by a cell.
void turnRegionIntoAnother(int region, int other, 
    vector<vector<cell>>& grid){
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j].region == region) {
                grid[i][j].region = other;
            }
        }        
    } 
}

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<cell>> grid(n, vector<cell>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c;
            cin >> c;
            grid[i][j] = {c, 0};
        }        
    }
    
    // Used to ensure region index uniqueness
    int regionCount = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // When we check a cell, it is possible that two or more previously
            // unconnected regions are in fact connected. When that happens,
            // we pick one and we turn other regions into it.
            
            // First ensure the cell has 1 not 0
            if(grid[i][j].content == 1){
                
                // Then fill this vector with the 1 cells adjacent
                // to it. Note that we only need to check above and to
                // the left as the cells to the right and below will later
                // be looped over anyway.
                vector<cell> neighbors;
                
                if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1].content == 1 
                    && grid[i-1][j-1].region > 0){
                    neighbors.push_back(grid[i-1][j-1]);
                }
                if (i-1 >= 0 && grid[i-1][j].content == 1 
                    && grid[i-1][j].region > 0){
                    neighbors.push_back(grid[i-1][j]);
                }
                if(i-1 >= 0 && j+1 < m && grid[i-1][j+1].content == 1 
                    && grid[i-1][j+1].region > 0){
                    neighbors.push_back(grid[i-1][j+1]);
                }
                if(j-1 >= 0 && grid[i][j-1].content == 1 
                    && grid[i][j-1].region > 0){
                    neighbors.push_back(grid[i][j-1]);
                }
                
                if(neighbors.size() != 0){
                    // Take first region
                    int region = neighbors[0].region;
                    // Loop over to make all other neighboring regions
                    // the same region if not already
                    for(int a = 1; a < neighbors.size(); a++){
                        turnRegionIntoAnother(neighbors[a].region, region, grid);
                    }
                    // Then set this cell as this region
                    grid[i][j].region = region;
                }
                // If the neighbors are all 0s (thus far), create a new region
                else{
                    // create new region
                    grid[i][j].region = regionCount;
                    regionCount++;
                }
            }
        }  
    }
    
    // Each region is the key, and the value is its size
    unordered_map<int, int> regions;
    // Loop over and count the cells in each region
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j].content == 1){
                regions[grid[i][j].region]++;
            }
        }        
    }
    
    int max = 0;
    for(auto i = regions.begin(); i != regions.end(); i++){
        if(i->second > max) max = i->second;
    }
    
    cout << max;
    
    return 0;
}
