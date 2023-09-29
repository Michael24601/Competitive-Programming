#include <bits/stdc++.h>

using namespace std;

// Max size of the bitset
constexpr int SIZE = 600 * 600;

void gameOfLifeIteration(bitset<SIZE>& grid, int n, int m){
    
    bitset<SIZE> copy;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int liveNeighbors{};
            int smallerI = (i-1 < 0 ? n-1 : i-1);
            int smallerJ = (j-1 < 0 ? m-1 : j-1);
            int biggerI = (i+1 >= n ? 0 : i+1);
            int biggerJ = (j+1 >= m ? 0 : j+1);

            if (grid[smallerI * m + smallerJ]) liveNeighbors++;
            if (grid[i * m + smallerJ]) liveNeighbors++;
            if (grid[biggerI * m + smallerJ]) liveNeighbors++;
            if (grid[smallerI * m + j]) liveNeighbors++;
            if (grid[biggerI * m + j]) liveNeighbors++;
            if (grid[smallerI * m + biggerJ]) liveNeighbors++;
            if (grid[i * m + biggerJ]) liveNeighbors++;
            if (grid[biggerI * m + biggerJ]) liveNeighbors++;

            
            if(liveNeighbors == 3){
                copy.set(i * m + j);
            }
            else if(grid[i * m + j] && liveNeighbors == 2){
                copy.set(i * m + j);
            }
            else{
                // Leave it 0
            }
        }
    }
    
    grid = copy;
}

int main() {
    long n, m, c;
    cin >> n >> m >> c;

    // To save on time, instead of going through all iterations up to c,
    // we save each state in a vector, and when we reach the original again,
    // we conclude we are in a cycle, and determine which of the previous
    // states we encountered we need to ouput.
    // This saves on time, but also wastes time since we will have to
    // compare the grid each time. For a fast comparison, we can use
    // bitsets to represent grids where grid[i][j] is the i*n+j bit.

    bitset<SIZE> grid;
    // Original grid
    bitset<SIZE> original;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == '*'){
                grid.set(i * m + j);
                original.set(i * m + j);
            }
        }
    }
    
    // To make the code go faster, if the original grid repeats, we know
    // the pattern, and can guess the minimum times we need to apply it
    // to get the same result as applying it c times

    for(int k = 1; k <= c; k++){
        gameOfLifeIteration(grid, n, m);

        if(grid == original){
            // Times it needs to be repeated to get c
            int timesNeeded = c % k;
            while(timesNeeded--){
                gameOfLifeIteration(grid, n, m);
            }
            // Leave the outer while loop
            break;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i * m + j]) cout << '*';
            else cout << '-';
        }
        cout << "\n";
    }
    
    return 0;
}