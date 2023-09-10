/*
    Website: Codechef
    Difficulty: 1666
    Language: c++
    Link: https://www.codechef.com/problems/RING_GAME
*/

#include <bits/stdc++.h>

using namespace std;

long pairs(int* a, long n, int m){
    int count{0};
    if(a[0] == a[n-1] && a[0]== m)
    count++;
    for(int i = 1; i <n; i++)
    {
        if(a[i]==a[i-1] && a[i]==m) 
        count++;
    }
    return (count);
}

int main() {
	int t;
	cin>>t;
	for(int i = 0; i < t; i++){
	    long n;
	    cin>>n;
	    int* a = new int[n];
	    for(long j = 0; j < n; j++){
	        cin >> a[j];
	    }
	    long one = pairs(a, n, 1);
	    long zero = pairs(a, n, 0);
	    long num = min(one, zero);
	    if((num)%2 == 0)
	    cout<<"BOB"<<'\n';
	    else
	    cout<<"ALICE"<<'\n';
	}
	return 0;
}
