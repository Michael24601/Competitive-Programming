/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/beautiful-triplets/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<long> v(n);
    for(int i = 0; i < n; i++){
        long c;
        cin >> c;
        v[i] = c;
    }
    int num = 0;
    for(int i = n-1; i > 1; i--){
        int n1 = count(v.begin(), v.begin() + i, (v[i] - d));
        int n2 = count(v.begin(), v.begin() + i, (v[i] - 2*d));
        num += n1*n2;
    }
    
    cout << num;
    
    return 0;
}