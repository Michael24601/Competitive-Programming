 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/B
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= a; j++) {
			if (i == a / 2 + 1 && j == a / 2 + 1)
				cout << 'X';
			else if (i <= a / 2 && j == i)
					cout << '\\';
			else if (i <= a / 2 && j == a-i+1)
					cout << '/';
			else if (i >= a / 2 + 1 && j == i)
					cout << '\\';
			else if (i >= a / 2 + 1 && j == a-i+1)
					cout << '/';
			else
				cout << '*';
		}
		cout << "\n";
	}
 
	return 0;
}