/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/J
*/


#include <bits/stdc++.h>

using namespace std;
 
int main() {
    
    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            for (int c = 1; c < 10; c++) {
                for (int d = 1; d < 10; d++) {
                    if (a + b == r1
                        && c + d == r2
                        && a + c == c1
                        && b + d == c2
                        && a + d == d1
                        && b + c == d2
                        && a!= b && a!=c && a!= d
                        && b!= d && b!=c
                        && c!=d) {
                        cout << a << " " << b << '\n' << c << " " << d;
                        return 0;
                    }
                    else if (a == 9 && b == 9 && c == 9 && d == 9) {
                        cout << -1;
                    }
                }
            }
        }
    }
 
    return 0;
}