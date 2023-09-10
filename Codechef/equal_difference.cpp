/*
    Website: Codechef
    Difficulty: -
    Language: c++
    Link: https://www.codechef.com/problems/EQDIFFER (broken)
*/


#include <bits/stdc++.h>

using namespace std;

struct s{
    int i;
    int occ;
};

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>> n;
	    int* a = new int[n];
	    vector<s> o;
	    for(int i =0; i < n; i++)
	    cin>>a[i];
	    sort(a, a+n);
	    int count = 1;
	    for(int i =0; i < n; i++){
	        if(i == n - 1){
	             o.push_back(s{a[i], count});
	        }
	        else if(a[i] == a[i+1]){
	            count++;
	        }
	        else{
	            o.push_back(s{a[i], count});
	            count = 1;
	        }
	    }
	    int max = 0;
	    for(int i =0; i < o.size(); i++){
	        if(o[i].occ > max)
	            max = o[i].occ;
	    }
	    if(n <= 1){
	        cout<<0<<"\n";
	    }
	    else if(max <= 2){
	        cout<< n - 2<<"\n";
	    }
	    else
	    cout<<n-max<<"\n";
	}
	return 0;
}
