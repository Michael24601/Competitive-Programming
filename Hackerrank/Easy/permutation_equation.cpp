/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/permutation-equation/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> p;
    vector<int> r;
    p.resize(n+1);
    r.resize(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    
    for(int i = 1; i <= n; i++){
        int n1 = find(p.begin(), p.end(), i) - p.begin();
        int n2 = find(p.begin(), p.end(), n1) - p.begin();
        r[i] = n2;
        cout << r[i] << "\n";
    }
    
    
    return 0;
}