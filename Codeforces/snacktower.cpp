 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/K
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool* left = new bool[n] {};
	int latest{0};
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if ((latest == 0 && num == n) || (latest > 0 && num == latest- 1)) {
			cout << num << " ";
			latest = num;
			while (true) {
				if (latest == 1) {
					return 0;
				}
				else if (left[latest - 2] ) {
					cout << latest -	1<<" ";
					latest--;
				}
				else {
					break;
				}
			}
			cout << "\n";
		}
		else {
			left[num - 1] = true;
			cout << "\n";
		}
	}
 
	return 0;
}