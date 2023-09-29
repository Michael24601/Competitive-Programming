/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/09f92a575cc006d4a6a7f525f370ec30/
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    // Last digit of fibonaci numbers follows a 60 cycle
    vector<short> f(61);
    f[0] = 0;
    f[1] = 1;
    // We only store the last digit
    for (int i = 2; i <= 60; i++) {
        f[i] = (f[i-1] + f[i-2]) % 10;
    }

    while(t--){
        long  m;
        cin >> m;
        
        cout << f[m % 60 + 1] << "\n"; 
    }
}