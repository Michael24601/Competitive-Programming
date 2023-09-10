/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/compare-the-triplets/problem
*/


#include <bits/stdc++.h>

using namespace std;

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

    int s1{}, s2{};
    for(int i = 0; i < 3; i++){
        if(a[i] > b[i]){
            s1++;
        }
        else if(b[i] > a[i]){
            s2++;
        }
    }

    cout << s1 << " " << s2;

    return 0;
}
