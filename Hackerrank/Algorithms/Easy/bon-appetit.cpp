/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/bon-appetit/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
  
    int n, k, b;
    cin >> n >> k;
    double sum{};
    for(int i =0; i < n; i++){
        int c;
        cin >> c;
        if(i != k){
            sum += c;
        }
    }
    cin >> b;
    sum /= 2.0;
    if(b != sum){
        cout << (b - sum);
    }
    else{
        cout << "Bon Appetit";
    }

    return 0;
}
