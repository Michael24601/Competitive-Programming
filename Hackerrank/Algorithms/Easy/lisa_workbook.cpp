/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/lisa-workbook/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int page = 1;
    int special = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        for(int j = 0; num > 0; j++){
            if(num - k > 0){
                if(page <= (j+1)*k && page >= j*k+1)
                    special++;
                num-=k;
            }
            else{
                if(page >= j*k+1 && page <= j*k + num)
                    special++;
                num = 0;
            }
            page++;
        }
    }
    cout << special;
    return 0;
}