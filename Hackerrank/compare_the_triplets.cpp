/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/compare-the-triplets/problem
*/


#include <bits/stdc++.h>

using namespace std;

int* compareTriplets(int* a, int* b) {
    int* s = new int[2];
    s[0] = s[1] = 0;
    for(int i = 0; i < 3; i++){
        if(a[i] > b[i]){
            s[0]++;
        }
        else if(b[i] > a[i]){
            s[1]++;
        }
    }
    return s;
}

int main() {

    int* a, *b;
    a = new int[3];
    b = new int[3];

    for(int i = 0; i < 3; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 3; i++){
        cin >> b[i];
    }

    int* c = compareTriplets(a, b);
    cout << c[0] << " " << c[1];

    return 0;
}
