/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/Q
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
 
	long long n;
	cin >> n;
	unsigned long long* array = new unsigned long long[n];
	long long num{};
	unsigned long long sum{};

    // We receive numbers as inputs corresponding to a bulb we just turned
    // on in a list of bulbs. A bulb turns blue if all the bulbs before it
    // are on. We want to know the number of iterations (moments in the
    // experiment) in which all bulbs are blue. This means that we need
    // to know the number of iterations in which the numbers we have
    // are the first consecutive numbers up to a point and no more.
    // We note that since the numbers we get each iterations are unique, and
    // since we always get exactly one number, the only way we have the first
    // consecutive numbers up to a point and no more is if we have the
    // first n numbers on the nth iteration, or in other words, if the
    // sum of our numbers is the sum of the first n numbers, which we easily
    // calculate with the sum formula. Since this sum is unique, we can
    // always tell if we have the first n numbers.
	for (unsigned long long i = 0; i < n; i++) {
		cin >> array[i];
		sum += array[i];
		if (sum == (i+1)*(i+2)/2)
			num++;
	}

	cout << num;
 
	return 0;
}