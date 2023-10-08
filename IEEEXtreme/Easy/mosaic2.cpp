/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/mosaic2
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    long long w, h, a, b, m, c;
    cin >> w >> h >> a >> b >> m >> c;
    long long hDiff = h % b;
    long long wDiff = w % a;
    long long wNeeded = ceil((double)w / a);
    long long hNeeded = ceil((double)h / b);
    if(hDiff == 0 && wDiff == 0){
        cout << fixed << setprecision(0) 
        << ceil((wNeeded * hNeeded) / 10.0) * m;
    }
    else if (hDiff == 0){
        cout << fixed << setprecision(0) 
            << c * h + ceil((wNeeded * hNeeded) / 10.0) * m;
    }
    else if (wDiff == 0){
        cout << fixed << setprecision(0) 
            << c * w + ceil((wNeeded * hNeeded) / 10.0) * m;
    }
    else{
        cout << fixed << setprecision(0)
            << c * (w + h) + ceil((wNeeded * hNeeded) / 10.0) * m;
    }
}