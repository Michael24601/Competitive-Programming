/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/a-very-big-sum/problem
*/


#include <bits/stdc++.h>

using namespace std;


int main() { 
    int n;
    cin >> n;
    long long m{};
    for(int i = 0; i < n; i++){
        long long c;
        cin >> c;
        m += c;
    }
    cout << m << "\n";

    return 0;
}
