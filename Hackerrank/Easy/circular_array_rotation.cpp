/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/circular-array-rotation/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    k = k%n;
    vector<int> v2;
    v2.resize(n);
    for(int i = 0; i < n; i++){
        v2[(i + k)%n] = v[i];
    }

    for(int i = 0; i < q; i++){
        int t;
        cin>>t;
        cout << v2[t] << "\n";
    }
    return 0;
}