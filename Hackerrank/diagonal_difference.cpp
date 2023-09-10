/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/diagonal-difference/problem
*/


#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>>& arr) {
    long n1{}, n2{};
    for(int i = 0; i < arr.size(); i++){
        n1 += arr[i][i];
        n2 += arr[arr.size()-i-1][i];
    }
    return abs(n1 - n2);
}

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

    int result = diagonalDifference(v);

    cout << result;

    return 0;
}
