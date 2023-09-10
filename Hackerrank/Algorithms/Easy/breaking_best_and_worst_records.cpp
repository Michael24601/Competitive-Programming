/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/breaking-best-and-worst-records/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* scores = new int[n];
    cin >> scores[0];
    int min{scores[0]}, max{scores[0]};
    int minc{}, maxc{};
    for(unsigned int i = 1; i < n; i++){
        cin >> scores[i];
        if(scores[i] < min){
            min = scores[i];
            minc++;
        }
        if(scores[i] > max){
            max = scores[i];
            maxc++;
        }
    }
    cout << maxc << " " << minc;

    return 0;
}
