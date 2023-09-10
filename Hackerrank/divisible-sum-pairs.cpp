/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    
    int c{};
    for(auto i = 0; i < ar.size(); i++){
        for(auto j = i + 1; j < ar.size(); j++){
            if((ar[i] + ar[j]) % k == 0){
                c++;
            }
        }
    }
    cout << c;

    return 0;
}
