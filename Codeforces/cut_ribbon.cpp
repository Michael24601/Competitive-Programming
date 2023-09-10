/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/R
*/


#include <bits/stdc++.h>
 
using namespace std;

// Max between 3 numbers
int max(int a, int b, int c) {
	int max = std::max(a, b);
	return std::max(c, max);
}
 
int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int* p = new int[n+1];
 
	
	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			p[i] = 0;
		}
		else {
			int A = (i - a >= 0) ? p[i - a] : -n-1;
			int B = (i - b >= 0) ? p[i - b] : -n-1;
			int C = (i - c >= 0) ? p[i - c] : -n-1;
				p[i] = max(A, B, C) + 1;
		}
	}
 
	cout << p[n];
	return 0;
}