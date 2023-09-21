/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/bomber-man/problem
*/


#include <bits/stdc++.h>

using namespace std;

vector<string> detonateBombs(vector<string>& grid){
    vector<string> newGrid(grid.size(), string(grid[0].size(), 'O'));
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 'O'){
                newGrid[i][j] = '.';
                if(i > 0) newGrid[i-1][j] = '.';
                if(i < grid.size()-1) newGrid[i+1][j] = '.';
                if(j > 0) newGrid[i][j-1] = '.';
                if(j < grid[i].size()-1) newGrid[i][j+1] = '.';
            }
        }
    }
    
    return newGrid;
}

void print(vector<string>& grid){
    for(int i = 0; i < grid.size(); i++){
        cout << grid[i] << "\n";
    }
}


int main(){
    
    int r, c;
    cin >> r >> c;
    long n;
    cin >> n;
    
    // It would be too slow to actually simulate the bombing process,
    // so instead, we note that there are 3 states the grid will be at,
    // the original, the "full", and 2 others it alternates between.
    // So that we have: original, full, other1, full, other2, full... and       
    // it repeats.
    vector<string> states[4]{vector<string>(r)};
    
    // The original
    for(int i = 0; i < r; i++){
        cin >> states[0][i];
    }
    
    // The full
    states[1] = vector<string>(r, string(c, 'O'));
    
    // The others
    states[2] = detonateBombs(states[0]);
    states[3] = detonateBombs(states[2]);
    
    if(n == 0 || n == 1){
        print(states[0]);
    }
    else if((n-1) % 4 == 2){
        print(states[2]);
    }
    else if ((n-1) % 4 == 0){
        print(states[3]);
    }
    else{
        print(states[1]);
    }
    
    return 0;
}








