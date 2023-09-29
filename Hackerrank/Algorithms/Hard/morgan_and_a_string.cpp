/*
    Website: Hackerank
    Difficulty: Hard
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/morgan-and-a-string/problem
*/


#include <bits/stdc++.h>

using namespace std;

// The problem wants us to compare the two strings and pop the
// smaller of the two. If they're equal, we comapre the elements
// below, and if they are equal, we repeat. To efficiently do this,
// instead of using a loop for this check, we can just compare the
// whole string: ca cb since ab < ac, if we take the first c first
// and then we are able to immediatly access a, instead of b.
// However, there is an edge case: When two or more "levels" are equal,
// but instead of reaching a tiebreaker character, we reach the end.
// This is usually not a problem, but if the charcaters after the equal
// characters are smaller than the equal characters, it causes a mistake:
// C and CB. Here, B is smaller than C, and C < CB, so we take the first
// C first, and are then forced to take the second C. Had we taken
// the second C first, we would have gotten C then B, which is smaller.
// To solve this, we just add a vlue at the end of each string larger than
// any uppercase letter, like "a", and pop it out later. 

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        string s = "";
        
        s1 += "a";
        s2 += "a";

        while (!s1.empty() && !s2.empty()) {
            if (s1.compare(0, s2.size(), s2) < 0) {
                s += s1[0];
                s1.erase(s1.begin());
            } else {
                s += s2[0];
                s2.erase(s2.begin());
            }
        }

        s += s1;
        s += s2;
        
        s.pop_back();
        s.pop_back();

        cout << s << "\n";
    }

    return 0;
}
