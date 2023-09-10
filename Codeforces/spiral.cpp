 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/Y
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
 
	int n, m;
	cin >> n >> m;
	long long** a = new long long* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new long long[m];
	}
 
	int num = n * m;
 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>> a[i][j];
		}
	}
 
	for (int i = 0; i < m; i++) {
		cout << a[0][i]<<" ";
	}
	num -= m;
 
	for (int i = 1; num > 0; i++) {
		for (int j = i; j <= n - i; j++) {
			cout << a[j][m - i]<<" ";
			num--;
		}
		if (num <= 0)
			break;
		for (int j = m - i - 1; j >= i - 1; j--) {
			cout << a[n - i][j]<<" ";
			num--;
		}
		if (num <= 0)
			break;
		for (int j = n - i - 1; j >= i; j--) {
			cout << a[j][i - 1]<<" ";
			num --;
		}
		if (num <= 0)
			break;
		for (int j = i; j <= m-i-1; j++) {
			cout << a[i][j]<<" ";
			num--;
		}
	}
	return 0;
}