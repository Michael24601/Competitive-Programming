/*
    Website: Codechef
    Difficulty: 1044
    Language: c++
    Link: https://www.codechef.com/problems/ODDPAIRS
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
	cin>>t;
	for(int l = 0; l<t; l++){
	    long n;
	    cin>> n;
	    long odd;
	    if(n%2==0){
	        odd = n/2;
	    }
        else
            odd = (n/2) + 1;
        if(n <=1)
            cout<<0<<'\n';
        else
        std::cout<<odd*(n-odd)*2<<'\n';
	}
	return 0;
}
