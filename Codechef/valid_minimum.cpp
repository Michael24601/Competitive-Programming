/*
    Website: Codechef
    Difficulty: 1132
    Language: c++
    Link: https://www.codechef.com/problems/VALIDMIN
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	int size;
	cin >> size;
	for(int i = 0; i < size; i++){
	    int m1, m2, m3;
	    cin >> m1 >> m2 >> m3;
	    if(m1 < m2){
	        if(m3 == m1)
	            cout<<"Yes\n"; 
	        else
	            cout<<"No\n";
	    }
	    else if (m2 < m1){
	        if(m3 == m2)
	            cout<<"Yes\n"; 
	        else
	            cout<<"No\n";
	    }
        else
        {
            if(m3 >= m1)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
	}
	return 0;
}
