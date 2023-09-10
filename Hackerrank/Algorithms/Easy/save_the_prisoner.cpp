/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/save-the-prisoner/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c, s;
        cin>> n >> c >> s;
        if((c+s-1)%n == 0) cout << n;
        else cout << (c+s -1 )%n;
        cout << "\n";
    }
    
    return 0;
}