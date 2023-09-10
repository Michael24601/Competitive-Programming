/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/drawing-book/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ,p;
    cin >> n >> p;
    
    n /= 2;
    p /= 2;
    
    cout <<  min(p, n - p);
    
    return 0;
}
