/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/U
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		string s, t, p;
		cin >> s >> t >> p;
		int os[26]{}, ot[26]{}, op[26]{};
 
		int index{};
		int count{};
		for (int i = 0; i < s.size(); i++) {
			while (index < t.size()) {
				if (t[index] == s[i])
				{
					index++;
					count++;
					break;
				}
				index++;
			}
		}
 
		if (count < s.size()) {
		cout << "NO\n";
			continue;
		}
 
		for (int i = 0; i <= 25; i++) {
			for (int j = 0; j < p.size(); j++)
				if (p[j] == char(i + 'a'))
					op[i]++;
			for (int j = 0; j < s.size(); j++)
				if (s[j] == char(i + 'a'))
					os[i]++;
			for (int j = 0; j < t.size(); j++)
				if (t[j] == char(i + 'a'))
					ot[i]++;
		}
		for (int i = 0; i < 26; i++) {
			if (ot[i] > os[i] + op[i]) {
				cout << "NO\n";
				break;
			}
			if (i == 25) {
				cout << "YES\n";
			}
		}
	}
	return 0;
}