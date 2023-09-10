/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/picking-numbers/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int max = 0;
    
    vector<int> v;
    v.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    for(int i = 0; i < n; i++){
        int c1{}, c2{};
        for(int j = 0; j < n; j++){
            if(v[j] == v[i] || v[j] == v[i] - 1){
                c1++;
            }
            else if (v[j] == v[i] || v[j] == v[i] + 1){
                c2++;
            }
        }
        if(c1 > max) max = c1;
        if(c2 > max) max = c2;
    }
    
    cout << max;
    
    return 0;
}