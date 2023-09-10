/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/equality-in-a-array/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a [100]{};
    for(int i =0; i < n; i++){
        int c;
        cin >> c;
        a[c]++;
    }
    
    int maxIn = *(max_element(a, a+100));
    cout << n - maxIn;
    
    return 0;
    
}