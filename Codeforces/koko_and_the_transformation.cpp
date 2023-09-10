/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/C
*/


#include <bits/stdc++.h>

using namespace std;
 
int main() {
    
    long a, b;
    cin >> a >> b;
    long arrayA;
    long arrayB;
    long long sumA{};
    long long sumB{};
    for (long i = 0; i < a; i++) {
        cin >> arrayA;
        sumA+=arrayA;
    }
    for (long i = 0; i < b; i++) {
        cin >> arrayB;
        sumB += arrayB;
    }
    cout << (sumA==sumB?"Yes":"No");
 
    return 0;
}