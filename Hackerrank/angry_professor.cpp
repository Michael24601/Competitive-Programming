/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/angry-professor/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n, k;
        cin>> n >> k;
        int c{};
        for(int i = 0; i < n; i++){
            int t;
            cin>> t;
            if(t <= 0) c++;
        }
        cout << (c < k ? "YES" : "NO") << "\n";
    }
    return 0;
}