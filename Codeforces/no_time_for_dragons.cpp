/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/P
*/


#include <bits/stdc++.h>

using namespace std;

struct s {
	long long a;
	long long b;
	long long diff;
};
 
// Custom comparison for the sort
bool swap(s const& s1, s const& s2) {
	if (s1.diff > s2.diff)
		return true;
	else
		return false;
}
int main()
{
	long long n;
	cin >> n;
	vector<s> array;
	array.resize(n);
 
 
	for (long long i = 0; i < n; i++) {
		cin >> array[i].a >> array[i].b;
		array[i].diff = array[i].a - array[i].b;
	}
 
    // We sort the dragons not by the number of soldiers needed to kill them
    // or the number that dies, but the difference between the two. Doing
    // that ensures the dragons that leave the most soldiers alives are
    // killed first, meaning that we can use the soldiers that remain for
    // the other battles.
	sort(array.begin(), array.end(), &swap);
 
    // We then calculte the number of needed soldiers, knowing it's the
    // minimum. 
	unsigned long long num{};
	long long rest{};
	for (long long i = 0; i < n; i++) {
 
		if (i == 0) {
			num += array[i].a;
			rest = array[i].a - array[i].b;
		}
		else if (i > 0) {
			if (rest < array[i].a) {
				 num += array[i].a - rest;
				rest = array[i].a - array[i].b;
			}
			else {
				rest = rest - array[i].b;
			}
 
		}
	}
	cout << num;
 
	return 0;
}