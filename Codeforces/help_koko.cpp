/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/O
*/


#include <bits/stdc++.h>

using namespace std;

bool prime(long long n) {
	if (n == 1) {
		return false;
	}
	for (long long  i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
 
int main()
{
	long long n, x;
	cin >> n >> x;
	long long* array = new long long[n];
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	for (long long i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 1) {
			if (!prime(array[i])) {
				cout << -1<< " ";
			}
			else {
				if (array[i] == 2) {
					cout << 0 <<" ";
				}
				else
					cout << 5 <<" ";
			}
		}
		else if(num == 2) {
			cout << 0 <<" ";
		}
	}
	return 0;
}