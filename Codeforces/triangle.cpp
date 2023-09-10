/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/Z
*/


#include <bits/stdc++.h>

using namespace std;

long length(long x1, long y1, long x2, long y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
 
bool check(long a, long b, long c) {
	long double d = sqrt(a), e = sqrt(b), f = sqrt(c);
	return (e + f > d && e + d > f && f + d > e);
}
 
int main() {
 
	long a[6];
	for (long i = 0; i < 6; i++) {
		cin >> a[i];
	}
 
	long l[3];
	l[0] = length(a[0], a[1], a[2], a[3]);
	l[1] = length(a[0], a[1], a[4], a[5]);
	l[2] = length(a[4], a[5], a[2], a[3]);
	sort(l, l + 3);
 
	if (check(l[0], l[1], l[2]) && l[2] == l[1] + l[0]) {
		cout << "RIGHT";
		return 0;
	}
 
	for (long i = 0; i < 6; i++) {
		a[i]++;
		l[0] = length(a[0], a[1], a[2], a[3]);
		l[1] = length(a[0], a[1], a[4], a[5]);
		l[2] = length(a[4], a[5], a[2], a[3]);
		sort(l, l + 3);
		if(check(l[0], l[1], l[2]) && l[2] == l[1] + l[0]) {
			cout << "ALMOST";
			return 0;
		}
		a[i] -= 2;
		l[0] = length(a[0], a[1], a[2], a[3]);
		l[1] = length(a[0], a[1], a[4], a[5]);
		l[2] = length(a[4], a[5], a[2], a[3]);
		sort(l, l + 3);
		if (check(l[0], l[1], l[2]) && l[2] == l[1] + l[0]) {
			cout << "ALMOST";
			return 0;
		}
		a[i]++;
	}
	cout << "NEITHER";
 
	return 0;
}