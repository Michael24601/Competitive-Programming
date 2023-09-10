/*
    Website: Codechef
    Difficulty: 1415
    Language: c++
    Link: https://www.codechef.com/problems/COLOUR
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    
	long t;
	cin>>t;
	while(t--){
	    int x[3];
	    cin>>x[0]>>x[1]>>x[2];
	    int count{};
	    if(x[0] > 0){ 
	        count++;
	        x[0]--;
	    }
	    if(x[1] > 0){ 
	        count++;
	        x[1]--;
	    }
	    if(x[2] > 0) {
	        count++;
	        x[2]--;
	    }
	    sort(x, x+3);
	    if(x[2] > 0 && x[1] > 0){ 
	        count++;
	        x[1]--;
	        x[2]--;
	    }
	    if(x[2] > 0 && x[0] > 0) {
	        count++;
	        x[0]--;
	    }
	    if(x[1] > 0 && x[0]>0){ 
	        count++;
	    }
	    cout<<count<<'\n';
	}
	return 0;
}
