/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/mosaic1
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, p;
    cin >> n >> p >> b;
    int sumP{}, sumB{};
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        sumP += m;
        cin >> m;
        sumB += m;
    }
    cout << fixed << setprecision(0) 
        << ceil(sumB/10.0) * b + ceil(sumP/10.0) * p;
    
    return 0;
}