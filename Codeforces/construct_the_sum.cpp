/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/E
*/


#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int t;
    cin >> t;
    while (t--) {
        unsigned long long s, r;
        cin >> s >> r;
        if ((s * (s + 1) / 2) < r) {
            cout << -1 << "\n";
        }
        else {
            unsigned long long sum{ 0 };
            unsigned long long n{ 0 };
            vector<unsigned long long> v;
            for (unsigned long long i = s; i >= 1; i--) {
                if (sum + i <= r) {
                    sum += i;
                    n++;
                    v.push_back(i);
                }
                if (sum == r) {
                    break;
                }
            }
            cout << n;
            for (unsigned long long j = 0; j < n; j++)
                cout << " " << v[j];
            cout << '\n';
        }
    }
    return 0;
}