/*
    Website: Codechef
    Difficulty: 838
    Language: c++
    Link: https://www.codechef.com/problems/LOOP
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
	short size;
	cin>>size;
	for(int i = 0; i<size; i++){
	    int a, b, l;
	    cin>>a>>b>>l;
	    if(abs(b-a)<=l/2)
	    std::cout<< abs(b-a)<<"\n";
	    else
	    std::cout<<(l-abs(b-a))<<"\n";
	}
	return 0;
}
