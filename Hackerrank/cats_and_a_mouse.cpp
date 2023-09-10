/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/cats-and-a-mouse/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int q;
    cin >> q;
    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        if(abs(x - z) == abs(y-z)){
            cout << "Mouse C";
        }  
        else if (abs(x - z) > abs(y - z)){
            cout << "Cat B";
        }
        else{
            cout << "Cat A";
        }
        cout << " \n";
    }
    
    return 0;
}