/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long p, q;
    
    cin >> p >> q;
    
    bool f = false;
    for(long i = p; i <= q; i++){
        int d = to_string(i).size();
        string s = to_string((long)(pow(i, 2)));

        if(stol(s.substr(s.size() - d, d)) + 
            (s.substr(0, s.size() - d).size() != 0 ? 
            stol(s.substr(0, s.size() - d)) : 0) == i) {

            f = true;
            cout << i << " ";
        }
    }
    if(!f){
        cout << "INVALID RANGE";
    }
    
    return 0;
}