/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/gaius-letters
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    // Each letter from 0 to 26 (a to z) maps to 
    char c[]{'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 
    'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
    'k', 'l', 'm', 'n'};
    char C[]{'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N'};
    // Note that they are shifted circularly around all lowercase
    // and uppercase letters

    string s;
    getline(cin, s);
    
    for(int j = 0; j < s.size(); j++){
        char i = s[j];
        if(i <= 'z' && i >= 'a'){
            cout << c[i - 'a'];
        }
        else if (i <= 'Z' && i >= 'A'){
            cout << C[i - 'A'];
        }
        else{
            cout << i;
        }
    }
    
    return 0;
}



