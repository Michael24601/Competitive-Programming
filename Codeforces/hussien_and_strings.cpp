/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/D
*/


#include <bits/stdc++.h>

using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
    char a1, b1, a2, b2;
    int n = 0;
    bool repeats{false};
    if (a.size() != b.size()) {
        cout << "NO";
        return 0;
    }
    for (long i = 0; i < a.size(); i++) {
        char c = a[i];
        if (a[i] != b[i]) {
            n++;
            if (n == 1) {
                a1 = a[i];
                b1 = b[i];
            }
            else if (n == 2) {
                a2 = a[i];
                b2 = b[i];
            }
        }
        if(!repeats)
        for (long j = i + 1; j <= a.size(); j++) {
            if (c == a[j])
                repeats = true;
        }
    }
    if (n == 0 && repeats) {
        cout << "YES";
    }
    else if (n > 2 || a2 != b1 || a1 != b2) {
        cout << "NO";
    }
    else
        cout << "YES";
 
    return 0;
}