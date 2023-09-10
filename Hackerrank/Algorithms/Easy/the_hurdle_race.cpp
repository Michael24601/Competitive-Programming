/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/the-hurdle-race/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>> n >> k;
    vector<int> v;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int max = *(max_element(v.begin(), v.end()));
    if(k > max) cout << 0;
    else cout << (max - k);
    return 0;
}