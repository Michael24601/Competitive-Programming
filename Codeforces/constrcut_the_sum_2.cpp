/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/G
*/


#include <bits/stdc++.h>
 
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		unsigned long long n, s;
		cin >> n >> s;
		if ((n) * (n + 1) / 2 < s) {
			cout << -1 << '\n';
			continue;
		}
		else
		{
			for (unsigned long long i = n; i > 0; i--) {
				if (s > i) {
					s -= i;
					cout << i << " ";
				}
				else if (s == i) {
					cout << i << " ";
					break;
				}
			}
			cout << "\n";
		}
	}
	return 0;
}