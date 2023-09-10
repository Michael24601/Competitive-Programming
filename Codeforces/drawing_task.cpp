/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223207/problem/A
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
 
	vector<vector<char>> a(n , vector<char> (m, 0)); 
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = '.';
		}
	}
 
	while (q--) {
		int r1, r2, c1, c2;
		char c;
		cin >> r1 >> c1 >> r2 >> c2;
		cin >> c;
 
		for (int i = min(r1, r2); i <= max(r2, r1); i++) {
			for (int j = min(c1, c2); j <= max(c2, c1); j++) {
				a[i-1][j-1] = c;
			}
		}
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout<< a[i][j];
		}
		 cout<<'\n';
	}
	
	return 0;
}