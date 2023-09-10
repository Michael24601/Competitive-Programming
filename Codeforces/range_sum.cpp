 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/D
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	long a;
	cin >> a;
	while (a--) {
		unsigned long long n, m;
		cin >> n >> m;
		cout << (max(m, n) - min(m, n) + 1) * (n + m) / 2 <<"\n";
	}
	return 0;
}