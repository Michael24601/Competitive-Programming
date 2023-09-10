/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/E
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	unsigned long long a;
	cin >> a;
	cout << (a) / 4 << " " <<(((a) / 4) % 2 == 0 ? (a) % 4 : 3-(a)%4);
	return 0;
}