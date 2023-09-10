/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/M
*/


#include <bits/stdc++.h>

using namespace std;
 
int main(){
    string s;
    int k;
    int numL{}, numC{}, numS{};
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*')
            numS++;
        else if (s[i] == '?')
            numC++;
        else
            numL++;
    }
    if ((k < numL - numS - numC) || (k > numL && numS == 0)) {
        cout << "Impossible";
    }
    else {
        string newS;
        int n = numL;
        for (int i = 0; i<s.size(); i++) {
            if (s[i] == '*' && k > n) {
                while (k > n) {
                    newS.push_back(s[i - 1]);
                    n++;
                }
            }
            else if ((s[i + 1] == '*' || s[i + 1] == '?') && k < n)
               n-- ;
            else if (s[i] == '*' || s[i] == '?')
                ;
            else {
                newS += s[i];
            }
        }
        cout << newS;
    }
}