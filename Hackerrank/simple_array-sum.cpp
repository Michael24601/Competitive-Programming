/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/simple-array-sum/problem
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int sum{};
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        sum += c;
    }
    cout << sum;

    return 0;
}

