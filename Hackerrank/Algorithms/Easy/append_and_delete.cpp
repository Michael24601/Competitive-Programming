/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/append-and-delete/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    string s, t;
    cin >> s >> t >> k;
    int inCommon = 0;
    for(int i = 0; i < t.size() && i < s.size(); i++){
        if(s[i] != t[i]){
            break;
        }
        else{
            inCommon ++;
        }
    }
    
    int removed = s.size() - inCommon;
    int added = t.size() - inCommon;
    
    if(k < removed){
        cout << "No";
    }
    else{
        k -= removed;
        if(k == added){
            cout << "Yes";
        }
        else if (k < added){
            cout << "No";
        }
        else if(k - inCommon >= t.size()){
            cout << "Yes";
        }
        else if((k - added) % 2 == 0){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
    }
    
    return 0;
}