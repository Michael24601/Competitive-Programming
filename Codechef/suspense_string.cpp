/*
    Website: Codechef
    Difficulty: 1239
    Language: c++
    Link: https://www.codechef.com/problems/SUSSTR
*/


#include <bits/stdc++.h>

using namespace std;

int main() {

    int m;
	cin>>m;
	while(m--){
	    int n;
	    string s;
	    cin>>n;
	    cin>>s;
	    string t="";
	    for(int i = 0; s.size() > 0; i++){
	        if(i%2 == 0){
	            if(s[0] == '0')
	                t.insert(0, "0");
	            else
	                t+="1";
	            s.erase(0, 1);
	        }
	        else{
	            if(s[s.size()-1] == '1')
	                t.insert(0, "1");
	            else
	                t+="0";
	            s.erase(s.size()-1);
	        }
	    }
	    cout<<t<<'\n';
	}

	return 0;
}
