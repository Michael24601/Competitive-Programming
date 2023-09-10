/*
    Website: Codechef
    Difficulty: 627
    Language: c++
    Link: https://www.codechef.com/problems/MAXTASTE
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	short size;
	cin>>size;
	for(int i =0; i < size; i++){
	    short a, b, c, d;
	    cin>>a>>b>>c>>d;
	    cout<<((a>b)?a:b) + ((c>d)?c:d)<<"\n";
	}
	return 0;
}
