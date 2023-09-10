/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/mininum_distances/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    
    vector<long> lastIndex(100000, -1);
    int n;
    cin >> n;
    // Larger than largest possible number as a base
    long min = 100000;
    for(int i = 0; i < n; i++){
        long c;
        cin >> c;
        if(lastIndex[c] == -1){
            lastIndex[c] = i;
        }
        else{
            if(i - lastIndex[c] < min){
                min = i - lastIndex[c];
            }
            lastIndex[c] = i;
        }
    }
    
    cout << (min < 100000 ? min : -1) ;
    
    
    return 0;
}