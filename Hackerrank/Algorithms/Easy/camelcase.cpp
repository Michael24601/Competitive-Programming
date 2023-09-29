/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/camelcase/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int c{};
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')  c++;
    }
    cout << c+1;
}