/*
    Website: Codechef
    Difficulty: 1264
    Language: c++
    Link: https://www.codechef.com/problems/MAKEABEQUAL
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i =0; i <t; i++){
	    int n;
	    cin>>n;
	    int* a = new int [n];
	    int* b = new int[n];
	    long long sumA{};
	     long long sumB{};
	    long long diffSum{};
	    for(int j =0; j < n; j++){
	        cin>>a[j];
	        sumA+= a[j];
	    }
	    for(int j =0; j < n; j++){
	        cin>>b[j];
	        sumB+= b[j];
	    }
	    if(sumA != sumB)
	        cout<<-1<<'\n';
	        else{
        	    for(int j = 0; j <n; j++){
        	        diffSum+= abs(a[j]-b[j]);
        	    }
        	    cout<<diffSum/2<<'\n';
	        }
	    
	}
	return 0;
}
