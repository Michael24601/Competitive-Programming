/*
    Website: IEEEXtreme
    Difficulty: Medium
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/lemons
*/


#include <bits/stdc++.h>

using namespace std;

// Binary search

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    
    // Because of the way we check on the health of water pumps,
    // and the fact that a faulty water pump i will give the impression
    // that either it, or any one above it, has damage, means that
    // the best approach is to do a binary-like-search.
    // The result is thus proportionl to the log_2 of the number of pumps.
    // We go with log_2(n-1) since the first pump is not faulty, and
    // multiply it by s, the time it takes to check any one pump.
    // Moreover, for the travel time, the worst case is that he ends up
    // at the last pump, so the travel time is m * (n-1) which are the
    // pumps he has to check.
    
    int result = (ceil(log2(n-1)) * s + m*(n-1));
    cout << result;
    
    return 0;
}