/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/pairs/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    // We can use a hashmap and search for the compliments of each value
    long n;
    long long k;
    cin >> n >> k;
    unordered_map<long long, int> m; 
    long long count{};
    
    for(long i = 0; i < n; i++){
        long long input;
        cin >> input;
        m[input]++;
    }
    
    // Each number has two compliments, for example, for k = 2,
    // 3 will have 1 and 5. We always search for the smaller, to avoid
    // repitition. 
    for(auto i = m.begin(); i != m.end(); i++){
        long long num = i->first;
        long long complement = num - k;
        if(m.count(complement)) count++;
    }
    
    cout << count;
}