/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/repeated-string/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    long long n;
    cin >> s >> n;
    long long c;
    for(long long i = 0; i < s.size(); i++){
        if(s[i] == 'a') c++;
    }
    c *= (n / s.size());
    for(long long  i = 0; i < n % s.size(); i++){
        if(s[i] == 'a') c++;
    }
    cout << c; 
    
    return 0;
}