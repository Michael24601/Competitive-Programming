/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/B
*/


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = s.size() + t.size();
    for (int i = 0; i < min(s.size(), t.size()); i++) {
        if (s[s.size() -i -1] != t[t.size()-i-1]) {
            break;
        }
        n -= 2;
    }
    cout << n;
 
    return 0;
}