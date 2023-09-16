/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/stange-code/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long t;
    cin >> t; 
    long i = 3;
    long sum = i;
    while(sum < t){
        i*=2;
        sum += i;
    }
    // Number of values we go down the last iterations before the timer stops
    long countNums = t - sum + i;
    // The output is the first value of this iteration, - the different
    // between it and the time, which is the number of values we went down
    // before the we reach t.
    cout << i - countNums + 1;  
    
    return 0;
}