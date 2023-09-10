/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/cavity-map/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    string* arr = new string[n];
    // Keep seperate copy for the final result as to keep using the first
    // array in our calculations without ruining it with Xs.
    string* copy = new string[n];

    for(int i = 0; i< n ;i++){
        cin >> arr[i];
        copy[i] = arr[i];
    }
    
    cout << copy[0] << "\n";
    for(int i =1; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            if(arr[i][j] > arr[i+1][j] &&
            arr[i][j] > arr[i-1][j] &&
            arr[i][j] > arr[i][j+1] &&
            arr[i][j] > arr[i][j-1])
                copy[i][j] = 'X';
        }
        cout << copy[i] << "\n";
    }
    if(n > 1)
    cout << copy[n-1] << "\n";
    
    return 0;
}