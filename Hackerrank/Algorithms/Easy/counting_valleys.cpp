/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/counting-valleys/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int lev{};
    int v {};
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        char t = s[i];
        if(t == 'D') {
            if(lev == 0)
                v++;
            lev--;
        }
        else 
            lev++;
    }
    
    cout << v;

    return 0;
}