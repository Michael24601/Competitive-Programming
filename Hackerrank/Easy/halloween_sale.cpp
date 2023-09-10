/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/halloween-sale/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int p, d, m , s;
    cin >> p >> d >> m >> s;
    int i = 0;
    while(true){
        s -= p;
        if(p-d >= m) p-= d;
        else p = m;
        if(s >= 0) i++;
        else break;
    }
    cout << i;
}