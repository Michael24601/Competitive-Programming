/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/the-grid-search/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        // Input
        int R, C, r, c;
        cin >> R >> C;
        string* G = new string[R];
        for(int i = 0; i < R; i++){
            cin >> G[i];
        }
        cin >> r >> c;
        string* p = new string[r];
        for(int i = 0; i < r; i++){
            cin >> p[i];
        }

        bool found = false;
        
        // Checks all rows for the first row of the pattern until we reach
        // r rows from the end, at which point the row is too low to accomodate
        // the full pattern.
        for(int i = 0; i < R && R-i >= r; i++){

            // Start the index at -1
            int index = -1;
            // Check all appearances of p[0] in each row i,
            // since it may appear twice until index becomes or remains -1,
            // indicating that we haven't found p[0] or found it but didn't
            // find the pattern beneath it, so that we have to check other rows
            // for another p[0].
            while(true){
                // Checks next appearance after the last appearance of the
                // the pattern p[0] in case it appears twice in the same
                // row.
                // The first time, it checks all the string, so using
                // index + 1 works as it is initially 0, so the entire
                // string, starting at 0, is checked (index is originally -1).
                index = G[i].find(p[0], index + 1);
                // Quit early if p[0] not here at all
                if(index == -1){
                    break;
                }
                int j = i+1, k = 1;
                // If index if found, check each row beneath it at the
                // correct index for the other rows of the patterns until
                // we find them all, or have to search other rows for p[0].
                while(G[j].substr(index, c) == p[k]){
                    j++;
                    k++;
                    if(k == r){
                        // Exits loops
                        found = true;
                        goto end_loops;
                    }
                }
            }
        }
        end_loops:
        if (found){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
