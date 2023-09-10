/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, j , k;
    cin >> i >> j >> k;
    int c{};
    
    for(int l = i; l <= j; l++){
        string s = to_string(l);
        reverse(s.begin(), s.end());
        if(abs(stoi(s) - l) % k == 0){
            c++;
        }
    }
    cout << c;
    return 0;   
}
