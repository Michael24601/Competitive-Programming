/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/birthday-cake-candles/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> candles(n);
    for (int i = 0; i < n; i++) {
        cin >> candles[i];
    }
    long max = *max_element(candles.begin(), candles.end());
    int count = 0;
    for(int i = 0; i < candles.size(); i++){
        if(candles[i] == max) count++;
    }
    return count;
    cout << count;
    
    return 0;
}
