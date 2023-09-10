/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/day-of-the=programmer/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int year;
    cin >> year;
    if(year >= 1919){
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            cout << "12.09." + to_string(year);
        }
        else {
            cout << "13.09." + to_string(year);
        } 
    }
    else if(year <= 1917){
        if(year % 4 == 0){
            cout << "12.09." + to_string(year);
        }
        else {
            cout << "13.09." + to_string(year);
        } 
    }
    else{
        cout << "26.09." + to_string(year);
    }
    return 0;
}
