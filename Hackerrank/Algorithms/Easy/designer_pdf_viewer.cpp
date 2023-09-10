/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    v.resize(26);
    for(int i = 0; i < 26; i++){
        cin >> v[i];
    }
    string s;
    cin>>s;
    int max = 0;
    for(int i = 0; i < s.size(); i++){
        if(v[s[i] - 'a'] > max)
            max = v[s[i] - 'a'];
    }
    cout << max * s.size();
    
    return 0;
}