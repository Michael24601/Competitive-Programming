/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/the-birthday-bar/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, m;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    cin >> d >> m;

    int count = 0;
    for(auto i = 0; i < s.size(); i++){
        if(i + m <= s.size()){
            int sum = 0;
            for(auto j = i; j < i + m; j++){
                sum+= s[j];
            }
            if(sum == d){
                count++;
            }
        }
        else{
            break;
        }
    }
    cout << count;

    return 0;
}
