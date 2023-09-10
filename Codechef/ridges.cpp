/*
    Website: Codechef
    Difficulty: 1505
    Language: c++
    Link: https://www.codechef.com/problems/PRDRG
*/


#include <bits/stdc++.h>

using namespace std;

long gcd(long a, long b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}


struct r{
    long n, d;
};


int main() {

	int n;
	cin >> n;
	while(n--){
	    long long t;
	    r ra;
	    cin>>t;
	    ra = {0, 1};
	    for(int i =0; i < t; i++){
	        if(i%2 == 0){
	            ra.n = ra.n*2 + 1; 
	            ra.d = ra.d*2;
	        }
	        else{
	            ra.n = ra.n*2 - 1; 
	            ra.d = ra.d*2;
	        }
	    }
	    long g = gcd(ra.n, ra.d);
	    ra.n/= g;
	    ra.d/= g;
	    cout<<ra.n <<" "<<ra.d<<" ";
	}

	return 0;
}
