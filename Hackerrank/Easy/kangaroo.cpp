/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/kangaroo/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    double x1, v1, x2, v2;
    cin>> x1 >> v1 >> x2 >> v2;
    
    double coef = (x1 - x2)/(v2 - v1);
    
    if(v1 == x2 && v1 == v2){
        cout << "YES";
    }
    else if (v1 == x2){
        cout << "NO";
    }
    else if (coef == static_cast<int>(coef) && coef > 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
