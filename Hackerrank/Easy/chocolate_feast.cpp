/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/chocolate-feast/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long n, c, m;
        cin >> n >> c >> m;
        int buy = n / c;
        n %= c;
        int newBuy = buy;
        while(newBuy/m != 0){
            int temp = newBuy/m;
            buy += temp;
            newBuy %= m;
            newBuy += temp;
        } 
        cout << buy << "\n";
    }
    return 0;
}