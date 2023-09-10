/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/diagonal-difference/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    long n1{}, n2{};
    for(int i = 0; i < n; i++){
        n1 += v[i][i];
        n2 += v[n-i-1][i];
    }
    cout << abs(n1 - n2);

    return 0;
}
