 /*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/X
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[5]{-1, -1, -1, -1, -1};
 
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		string s = to_string(num);
 
		if (s == "0")
			a[0]=num;
		else if (s.size()==3 && s[1]=='0' && s[2]=='0')
			a[1]=num;
		else if (s.size()==2 && s[1] == '0')
			a[2]=num;
		else if (s.size()==1)
			a[3]=num;
		else if (s.size()==2)
			a[4] = num;
	}
 
	vector<int> v;
	bool can = true;
	if (a[0] != -1) {
		v.push_back(a[0]);
	}
	if (a[1] != -1) {
		v.push_back(a[1]);
	}
	if (a[2] != -1) {
		v.push_back(a[2]);
		can = false;
	}
	if (a[3] != -1) {
		v.push_back(a[3]);
		can = false;
	}
	if (a[4] != -1 && can) {
		v.push_back(a[4]);
	}
 
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
	
}