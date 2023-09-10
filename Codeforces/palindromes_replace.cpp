/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/A
*/


#include <bits/stdc++.h>

using namespace std;
 
int main() {

    string s;
    cin >> s;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] == '?' && s[s.size() - i - 1] == '?') {
            s[i] = s[s.size() - i - 1] = 'a';
        }
        else if (s[i] == '?' && s[s.size() - i - 1] != '?') {
            s[i] = s[s.size() - i - 1];
        }
        else if (s[i] != '?' && s[s.size() - i - 1] == '?') {
            s[s.size() - i - 1] = s[i];
        }
        else if (s[i] != s[s.size() - i - 1])
        {
            cout << -1;
            return 0;
        }
    }
    if (s.size() % 2 == 1 && s[(s.size() / 2)] == '?') {
        s[(s.size() / 2)] = 'a';
    }
    cout << s;

    return 0;
}
