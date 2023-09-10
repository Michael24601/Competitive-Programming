/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/time-conversion/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    if(s[8] == 'P' && !(s[0] == '1' && s[1] == '2')){
        int n = (s[0] -'0')*10 + (s[1]-'0');
        n += 12;
        string s2 = to_string(n);
        s[0] = s2[0];
        s[1] = s2[1];
    }

    else if (s[8] == 'A' && s[0] == '1' && s[1] == '2'){
        s[0] = '0';
        s[1] = '0';
    }
    cout << s.substr(0, 8);
    return 0;
}
