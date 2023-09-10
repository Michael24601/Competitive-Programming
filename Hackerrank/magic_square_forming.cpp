/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/magic-square-forming/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    v.resize(9);
    for(int i = 0;i < 9; i++){
        cin>> v[i];
    }
    
    vector<int> ne;
    ne.resize(9);
    for(int i = 0; i < 9; i++){
        ne[i] = i+1;
    }
    
    int min{1000};
    for(int i = 0; i < 362880; i++){
        int sum = 0;
        if(ne[0] + ne[1] + ne[2] == ne[3] + ne[4] + ne[5] &&
        ne[0] + ne[1] + ne[2] == ne[6] + ne[7] + ne[8] &&
        ne[0] + ne[1] + ne[2] == ne[0] + ne[4] + ne[8] &&
        ne[0] + ne[1] + ne[2] == ne[2] + ne[4] + ne[6] &&
        ne[0] + ne[1] + ne[2] == ne[0] + ne[3] + ne[6] &&
        ne[0] + ne[1] + ne[2] == ne[1] + ne[4] + ne[7] && 
        ne[0] + ne[1] + ne[2] == ne[2] + ne[5] + ne[8]){
            for (int j = 0; j < 9; j++){
                sum += abs(ne[j] - v[j]);
            }
            if(sum < min){
                min = sum;
            }
        }
        next_permutation(ne.begin(), ne.end());
    }
    cout << min;
    
    return 0;
}