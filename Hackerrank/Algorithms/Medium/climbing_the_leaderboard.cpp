/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, m;
    cin>> n;

    map<int, int> p;
    
    for(int i = 0; i < n; i++){
        int t;
        cin>> t; 
        p[t]++;
    }
    
    cin >> m;
    
    auto rank = p.begin();
    int num = p.size() + 1;
    
    for(int i = 0; i < m; i++){
        int t;
        cin>>t;
        while(rank->first <= t && num != 1){
            rank++;
            num--;
        }
        cout << num << "\n";
    }

    return 0;
}
