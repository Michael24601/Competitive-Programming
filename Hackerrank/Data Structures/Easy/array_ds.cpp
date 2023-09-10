/*
    Website: Hackerank
    Difficulty: Easy
    Type: Data Structures
    Language: c++
    Link: https://www.hackerrank.com/challenges/array-ds/problem
*/


#include <bits/stdc++.h>

using namespace std;

void reverseArray(int n) {
    // anchor case
    if(n == 0){
        return;
    }
    else{
        int a;
        cin >> a;
        reverseArray( n-1);
        cout << a << " ";
    }
}

int main() {
    int n;
    cin >> n;
    reverseArray(n);
    return 0;
}
