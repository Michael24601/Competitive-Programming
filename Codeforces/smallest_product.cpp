/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/G
*/


#include <bits/stdc++.h>

using namespace std;
 
int main() {
 
	long long n;
	long double num = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long in;
		cin >> in;
		num *= pow(in, 1.0/n);
	}
 
	if (ceil(num) == num) {
		cout << num + 1;
	}
	else
		cout << fixed << static_cast<long long>(ceil(num));
 
 
	return 0;
}