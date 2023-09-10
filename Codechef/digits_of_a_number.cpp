/*
    Website: Codechef
    Difficulty: 1209
    Language: c++
    Link: https://www.codechef.com/problems/LONGSEQ
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int o{}, z{};
	    for(int i =0; i < s.size(); i++){
	        if(s[i]=='1')
	            o++;
	        else
	            z++;
	    }
	    if((o == 1 && z>=0) || (z == 1 && o >= 0)){
	        cout<<"Yes\n";
	    }
	    else
	    cout<<"No\n";
	}

	return 0;
}
