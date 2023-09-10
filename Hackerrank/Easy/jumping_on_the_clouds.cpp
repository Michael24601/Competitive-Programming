/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        v[i] = c;
    }
    int cur = 0;
    int jumps = 0;
    while(cur != n - 1){
        if(cur+2 < n && v[cur+2] == 0){
            cur+=2;
        }
        else{
            cur++;
        }
        jumps++;
    }
    cout << jumps;
    return 0;
}