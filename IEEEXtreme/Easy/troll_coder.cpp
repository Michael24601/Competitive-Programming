/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/troll-coder/
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; 
    cin >> n;
    
    // The strategy it to first give a query with all 0 bits.
    // We record the answer, and then, each of the
    // subsequent n queries, send a sequence with 1 in the
    // 0 to n-1th positions. If the answer is smaller than the
    // original, this bits is 0, otherwise it should be 1.
    // We use N+1 queries in total, each time.
    vector<bool> v(n, false);
    vector<bool> bits(n, false);
    int m, firstM;
    for(int i = 0; i <= n; i++){
        
        if(i != 0){
            v[i-1] = true;
        }
        
        cout << "Q ";
        for (int j = 0; j < n; j++) {
            cout << v[j] << " ";
        }
        cout.flush();
        
        if(i != 0){
            cin >> m;
            
            if(firstM < m){
                bits[i-1] = true;
            }
        }
        else{
            cin >> firstM;
        }
        
        v[i-1] = false;
    }
    
    cout << "A ";
    for (int j = 0; j < n; j++) {
        cout << bits[j] << " ";
    }
    cout.flush();
}