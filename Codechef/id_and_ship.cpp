/*
    Website: Codechef
    Difficulty: 847
    Language: c++
    Link: https://www.codechef.com/problems/FLOW010
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    short size;
    cin>>size;
	for(int i =0; i < size; i++){
	    char c;
	    cin>>c;
	    switch(c){
	        case 'B': case 'b':
	        cout<<"BattleShip\n";
	        break;
	        case 'C': case 'c':
	        cout<<"Cruiser\n";
	        break;
	        case 'D': case 'd':
	        cout<<"Destroyer\n";
	        break;
	        case 'F': case 'f':
	        cout<<"Frigate\n";
	    }
	}
	return 0;
}
