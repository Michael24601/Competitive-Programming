/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/taum-and-bday/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        long b, w, bc, wc, z;
        cin >> b >> w >> bc >> wc >> z;
        
        if(bc +z < wc ){
            cout << bc * (b+w) + w*z;
        }
        else if(wc +z < bc){
            cout << wc * (w+b) + b*z;
        }
        else{
            cout << wc *w + bc *b; 
        }
        cout << "\n";
    }
    
    return 0;
}