/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/staircase/problem
*/


#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
    for(int i = 0; i < n; i++){
        for(int j = n - i - 1; j > 0; j--){
            cout << " ";
        }
        for(int j = 0; j <= i; j++){
            cout << "#";
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    staircase(n);

    return 0;
}
