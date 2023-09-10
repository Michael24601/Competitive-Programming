/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>> n >> k;
    int * c = new int [n];
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int s = 0;
    int e = 100;
    do {
        s = (s+k)%n;
        if(c[s] == 1){
            e-=2;
        }
        e--;
    }while(s!= 0);
    
    cout << e;

    
    return 0;
}