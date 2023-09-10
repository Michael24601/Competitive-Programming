/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/V
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n>> m;
	for (int i = 0; i < n / m + 1; i++) {
		for (int j = 0; j < m; j++) {
			if (i * m + j >= n)
				return 0;
			cout << char(j + 'a');
		}
	}
	return 0;
}