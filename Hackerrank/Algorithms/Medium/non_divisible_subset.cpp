/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/non-divisible-subset/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long n, k;
    cin >> n >> k;   
    vector<long> v(k, 0);
    long sum = 0;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        v[c%k]++;
    }
    
    int mid = (v.size() % 2 == 0 ? v.size()/2 : v.size()/2 + 1);
    
    for(int i = 1; i < mid; i++){
        sum += max(v[i], v[k-i]);
    }
    
    if(v.size() % 2 == 0 && v[v.size()/2] >= 1){
        sum++;
    }
    if(v[0] >= 1){
        sum++;
    }

    cout << sum;
    
    return 0;
}
