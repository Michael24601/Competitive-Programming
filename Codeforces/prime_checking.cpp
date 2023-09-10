 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/B
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			cout << "NO";
			return 0;
		}
	}
	if (n == 1) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}