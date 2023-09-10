/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/N
*/


#include <bits/stdc++.h>

using namespace std;
 
int main() {
	unsigned long long e, m, b;
	cin >> e >> m >> b;
	unsigned long long e1 = e, b1 = b, m1 = m;
	unsigned long long min = std::min(e, m), score1{}, score2{};
	min = std::min(min, b);
	e1 -= min;
	b1 -= min;
	m1 -= min;
	score1 += min;
	if (e1 / 2 >= 1 && b1 >= 1) {
		score1 += std::min(e1 / 2, b1);
	}
	e1 = e; m1 = m; b1 = b;
	min = std::min(e1 / 2, b1);
	e1 -= min * 2;
	b1 -= min;
	score2 += min;
	if (e1 >= 1 && b1 >= 1 && m1 >= 1) {
		min = std::min(e1, m1);
		min = std::min(min, b1);
		score2 += min;
	}
	cout << max(score1, score2);
	return 0;
}