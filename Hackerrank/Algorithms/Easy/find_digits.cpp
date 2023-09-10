/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/find-digits/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t; 
    cin >> t;
    while(t--){
        int div = 0;
        long n;
        cin >> n;
        long num = n;
        while(n > 0){
            int l = n %10;
            if(l != 0 && num % l == 0){
                div++;
            }
            n /=10;
        }
        cout << div << "\n";
    }
    
    return 0;
}