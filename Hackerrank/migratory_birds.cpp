/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/migratory-birds/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> map;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        map[c]++;
    }
    // Get the max value in the map, referring to the occurence.
    // By default max returns the first max that is found in the
    // case of multiple maxs 
    auto max = *std::max_element(std::begin(map), std::end(map),
    [] (const decltype(map)::value_type & p1, 
        const decltype(map)::value_type & p2) {
        return p1.second < p2.second;
    });
    cout << max.first;

    return 0;
}
