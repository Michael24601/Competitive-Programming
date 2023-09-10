/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/L
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    long long l, r, s;
    cin>> l>> r>> s;
    long q;
    cin>>q;
    long long s1 = min(r, s);
    long long s2 = max(r, s);
    for(long i = 0; i < q; i++){
        double qi;
        cin>>qi;
        cout<<setprecision(8)<< (sqrt(2*qi)-l*sqrt(2))/(s1-s2)<<'\n';
    }
 
    return 0;
}