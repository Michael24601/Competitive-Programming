/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/sock-merchant/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>> n;
    vector<int> v;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    map<int, int> m;
    int sum{};
    for(auto i = v.begin(); i != v.end(); i++){
        m[*i]++;
        // Eeverytime our color (denoted by key) has an even numbered
        // value, that means we've made another pair and can increase
        // the sum
        if(m[*i] % 2 == 0){
            sum++;
        }
    }
    cout << sum;
    
    return 0;
}