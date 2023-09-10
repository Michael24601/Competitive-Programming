/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/cut-the-sticks/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n; 
    cin>> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int c;
        cin>> c;
        v.push_back(c);
    }
    
    sort(v.begin(), v.end());
    
    while(!v.empty()){
        cout << v.size() << "\n";
        int c = v[0];
        for(int i = 0; i < v.size(); ){
            v[i] = v[i] - c;
            if(v[i] == 0){
                v.erase(v.begin());
            }
            else{
                i++;
            }
        }
    }
}