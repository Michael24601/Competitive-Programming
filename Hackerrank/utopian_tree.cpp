/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/utopian-tree/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> c;
    c.resize(n);
    for(int i = 0; i < n; i++){
        cin>>c[i];
    }
    int max = *max_element(c.begin(), c.end());
    vector<int> m;
    m.resize(max + 1);
    m[0] = 1;
    for(int i = 0; i < max; i++){
        if(i%2 == 0)
            m[i+1] = m[i] * 2;
        else
            m[i+1] = m[i] + 1;
    }
    for(int i = 0; i < n; i++){
        cout << m[c[i]] <<"\n";
    }
    return 0;
}