/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<char, int> m;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        m[s[i]]++;
    }
    
    int max{};  // Most occurences
    int min{1000000};   // Least occurences
    for(auto i = m.begin(); i != m.end(); i++){
        if(i->second > max) max = i->second;
        if(i->second < min) min = i->second;
    }
    
    // If min and max are different, there should be one of max
    // only and every other one should be min, otherwise if they
    // are equal then all otheres are automatically equal.
    // The only exception is if everything is equal to max and
    // and the min is 1 (in which case it's deleted and that's that)
    
    if(min == max) {
        cout << "YES";
    }
    else{
        int equalToMax{};
        int equalToMin{};
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second == min){
                equalToMin++;
            }
            if(i->second == max){
                equalToMax++;
            }
        }
        if(equalToMin == 1 && equalToMax == m.size()-1){
            cout << "YES";
        }
        else if (equalToMin == m.size() - 1 && equalToMax == 1 && max - min == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }
    
    return 0;
}
