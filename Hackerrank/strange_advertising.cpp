/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/stange-advertising/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int k = 5;
    int s{0};
    for(int i = 0; i < n; i++){
        k/=2;
        s += k;
        k*=3;
    }
    cout << s;
    return 0;
}