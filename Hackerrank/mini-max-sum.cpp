/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/mini-max-sum/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<long> v(5);
    long long sum;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        sum+= v[i];
    }
    cout <<(sum - *max_element(v.begin(), v.end())) << " "
    << (sum - *min_element(v.begin(), v.end()));

    return 0;
}
