/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/plus-minus/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double p{}, m{}, z{}; 
    for(int i= 0; i < n; i++){
        int c;
        cin >> c;
        if(c > 0) p++;
        else if (c < 0) m++;
        else z++;
    }
    cout << (p/n) << "\n";
    cout << (m/n) << "\n";
    cout << (z/n) << "\n";

    return 0;
}
