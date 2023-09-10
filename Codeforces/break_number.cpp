/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/F
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	long long a;
	cin >> a;
	unsigned long long num;
	unsigned long long max{0};
	for (long long i = 0; i < a; i++) {
		cin >> num;
		unsigned long long times{};
		while (num % 2 == 0) {
			num /= 2;
			times++;
		}
		if (max < times)
			max = times;
	}
	cout << max;	
	return 0;
}