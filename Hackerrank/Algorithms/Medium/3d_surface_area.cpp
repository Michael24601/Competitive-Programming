/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/3d-surface-area/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    
    int sum{};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){      
            // Corner tower
            if((i == 0 && j == w-1) || (i == 0 && j == 0)
            || (j == 0 && i == h-1) || (i == h-1 && j == w-1)){
                // If corner is on a single tower, add 4 length sides
                if(h == 1 && w == 1){
                    sum += 4*a[i][j];
                }
                // If corner is on a line, we want 3 length sides
                else if (h == 1 || w == 1){
                    sum += 3*a[i][j];
                }
                // Else, it's a normal corner tower, and returns 2 side lengths
                else{
                    sum += 2*a[i][j];
                }
            }
            // Side (not corner)
            else if (i == 0 || i == h-1 || j == 0 || j == w-1) {
                // If side of a line, return 2 length sides
                if(h == 1 || w == 1){
                    sum += 2*a[i][j];
                }
                // Else normal side that returns 1 side length
                else{
                    sum += a[i][j];   
                }
            }

            // Check that if the columns on one of the 4 sides exist,
            // if it taller or not. If shorter, add faces the length of
            // the difference.
            if(i - 1 >= 0 && a[i-1][j] < a[i][j]){
                sum += a[i][j] - a[i-1][j];
            }
            if(i + 1 < h && a[i+1][j] < a[i][j]){
                sum += a[i][j] - a[i+1][j];
            }
            if(j + 1 < w && a[i][j+1] < a[i][j]){
                sum += a[i][j] - a[i][j+1];
            }
            if(j - 1 >= 0 && a[i][j-1] < a[i][j]){
                sum += a[i][j] - a[i][j-1];
            }
        }
    }
    // Top and bottom faces
    sum += 2*w*h;
    cout << sum;
    
    return 0;
}
