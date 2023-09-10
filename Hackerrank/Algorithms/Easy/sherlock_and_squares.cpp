/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/sherlock-and-squares/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        long a, b;
        cin >> a >> b;
        long start = a, end = b;
        while((long)(sqrt(start)) * (long)(sqrt(start)) != start 
        && start < b){
            start ++;
        }
        while((long)(sqrt(end)) * (long)(sqrt(end)) != end
        && end > a){
            end --;
        }
        if(start == b && end == a && ((long)(sqrt(a)) * (long)(sqrt(a)) != a))
        {
            cout << 0 << "\n";
        }
        else{
        cout << (sqrt(end) - sqrt(start) + 1) << "\n";
        }
    }
    
    return 0;
}