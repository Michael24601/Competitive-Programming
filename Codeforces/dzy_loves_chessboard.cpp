/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/S
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
 
	int n, m;
	cin >> n >> m;
	char** a = new char* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[m];
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '-')
				 cout<< '-';
			else {
				if ((i + j) % 2 == 0)
					cout<< 'B';
				else
					cout<< 'W';
			}
		}
		cout << '\n';
	}
 
	return 0;
}