/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/I
*/


#include <bits/stdc++.h>
 
using namespace std;

void add(string& s, char ch, int& n) {
    if ((s[0] == ch && s[1] == '>') || (s[2] == ch && s[1] == '<')) {
        n++;
    }
}
 
int main() {
    int a[3]{};
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 3; j++) {
            add(s, char('A'+j), a[j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[j] == i) {
                cout << char('A' + j);
                break;
            }
            if (j == 2) {
                cout << "Impossible";
                return 0;
            }
        }
    }
 
    return 0;
}