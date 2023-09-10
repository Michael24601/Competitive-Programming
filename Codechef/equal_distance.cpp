/*
    Website: Codechef
    Difficulty: -
    Language: c++
    Link: https://www.codechef.com/problems/EQDIS (broken)
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; 
    cin>> t;
	for(int i = 0; i < t; i++){
	    int n;
	    cin>>n;
	    int* array = new int [n];
	    int count{1};
	    for(int j = 0; j <n; j++){
	        cin>>array[j];
	    }
	    sort(array, array+n);
	    for(int j = 1; j <n; j++){
	        if(array[j] != array[j-1])
	            count++;
	    }
	    if(count%2 == 0 || count < n)
	        cout<<"YES"<<'\n';
	        else
	        cout<<"No"<<'\n';
	}
	return 0;
}
