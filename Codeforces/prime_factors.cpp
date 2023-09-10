 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/J
*/


#include <bits/stdc++.h>

using namespace std;

vector<long> func(long n) {
	static vector<long> primes;
	long n1 = -1, n2;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			n1 = i;
			break;
		}
	}
	if (n1 == -1) {
		primes.push_back(n);
		return primes;
	}
	else {
		n2 = n / n1;
		func(n1);
		func(n2);
		return primes;
	}
}
 
 
int main() {

	long n;
	cin >> n;
	vector<long> primes = func(n);
	sort(primes.begin(), primes.end());
	long count = 1;
	string s = "";
	if (primes.size() > 1) {
		for (int i = 0; i < primes.size()-1; i++) {
			if (primes[i] == primes[i + 1]) {
				count++;
			}
			else if (primes[i] != primes[i + 1]) {
				s += "(" + to_string(primes[i]) + "^"
                    + to_string(count) + ")*";
				count = 1;
			}
		}
		s += "(" + to_string(primes[primes.size()-1]) + "^"
            + to_string(count) + ")";
	}
	else {
		s += "(" + to_string(primes[0]) + "^1)";
	}
	cout << s;
    
	return 0;
}