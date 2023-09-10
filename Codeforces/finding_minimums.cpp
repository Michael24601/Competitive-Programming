/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/326907/problem/C
*/


#include <bits/stdc++.h>

using namespace std;

int min(int* a, int i, int j) {
	int min = a[i];
	for (int k = i+1; k <= j; k++) {
		if (a[k] < min)
			min = a[k];
	}
	return min;
}
 
 
int main() {
	int a, b;
	cin >> a>>b;
	int* arr = new int[a];
 
	for (int i = 0; i < a; i++)
		cin>>arr[i];
 
	for (int i = 0; i < a; i+=b) {
		if (i + b - 1 >= a) {
			cout << min(arr, i, a-1) << " ";
			break;
		}
		cout << min(arr, i, i + b - 1) << " ";
	}
 
	return 0;
}