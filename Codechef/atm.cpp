/*
    Website: Codechef
    Difficulty: 410
    Language: c++
    Link: https://www.codechef.com/problems/HS08TEST
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    cout<< setprecision(2)<< fixed;

    int a;
    float b;
    cin >> a >> b;
    float c = b-a - 0.5f;
    
    if ((a%5==0) && (c>=0)) {
        cout << c;
    } else {
        cout <<b;
    }

    return 0;
}
