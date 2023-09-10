/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/H
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (int(s[i] - '0') >= 5 && !(i == 0 && int(s[i] - '0') == 9)) {
            cout << (9 - (s[i] - '0'));
        }
        else
            cout << (s[i] - '0');
    }
    return 0;
}