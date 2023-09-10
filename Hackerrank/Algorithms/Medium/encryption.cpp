/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/encryption/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n = pow(s.size(), 0.5);
    vector<vector<char>> v;
    if(n* n == s.size()){
        v.resize(n, vector<char>(n, ' '));
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                v[i][j] = s[i*n + j]; 
            }
            
        }
    }
    else if (n*(n+1) >= s.size()){
        v.resize(n, vector<char>(n+1, ' '));
        for(int i = 0; i < n-1; i++){
            for(int j =0; j < n+1; j++){
                v[i][j] = s[i*(n+1) + j]; 
            }   
        }
        for(int i = (n-1)*(n+1), j = 0; i < s.size(); i++, j++){
            v[(n-1)][j] = s[i];
        }

    }
    else{
        v.resize(n+1, vector<char>(n+1, ' '));
        for(int i = 0; i < n; i++){
            for(int j =0; j < n+1; j++){
                v[i][j] = s[i*(n+1) + j]; 
            }   
        }
        for(int i = (n)*(n+1), j = 0; i < s.size(); i++, j++){
            v[n][j] = s[i];
        }
    }
    
    for(int i = 0; i < v[0].size(); i++){
        int boundary = (v[v.size()-1][i] == ' ' ? v.size() - 1 : v.size());
        for(int j = 0; j < boundary; j++){
            cout << v[j][i];
        }
        cout << " ";
    }

    return 0;
}