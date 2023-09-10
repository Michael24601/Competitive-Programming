/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/T
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
 
	int n;
	std::cin >> n;
 
	while (n >= 7) {
		std::cout << "ROYGBIV";
		n -= 7;
	}
	switch (n) {
	case 1:
		std::cout << "G"; break;
	case 2:
		std::cout << "GB"; break;
	case 3:
		std::cout << "GBI"; break;
	case 4:
		std::cout << "GBIV"; break;
	case 5:
		std::cout << "YGBIV"; break;
	case 6:
		std::cout << "OYGBIV"; break;
	}
 
 
	return 0;
}