/*
    Website: Codechef
    Difficulty: 717
    Language: c++
    Link: https://www.codechef.com/problems/FLOORS
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n >> m;
	    cout<< abs(((m%10 == 0)? m/10 - 1: m/10) - 
	    ((n%10 == 0)? n/10 - 1: n/10)) <<"\n";
	}
	return 0;
}
