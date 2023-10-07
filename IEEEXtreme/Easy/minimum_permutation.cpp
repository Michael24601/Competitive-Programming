/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/minimum-permutation
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    
    // We sort the set in ascending order and then loop
    // over both, printing the smaller element each time.
    // We can't sort the array a, as its elements can't change
    // order.
    sort(b.begin(), b.end());
    for(int i = 0, j = 0; i < n || j < m; ){
        if(i == n){
            cout << b[j] << " ";
            j++;
        }
        else if (j == m){
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] < b[j]){
            cout << a[i] << " ";
            i++; 
        }
        else{
            cout << b[j] << " ";
            j++;
        }
    }
}