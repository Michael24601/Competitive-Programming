/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/absolute-permutation/problem
*/


#include <bits/stdc++.h>

using namespace std;

void swapArray(int intervalLength, int* arr, int start){
    for(int i = 0; i < intervalLength; i++){
        swap(arr[start + i], arr[start + i + intervalLength]);
    }
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        if(k == 0){
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << "\n";
            continue;
        }
        
        // Our strategy will be to swap each two numbers with each
        // other. If it doesn't work, we can assume nothing will.
        // So it only works if k * 2 divides n, since we will apply
        // our strategy to each blocks of k/2:
        // (1 2) (3 4) (5 6) (7 8) with k = 2 -> (2 1) (4 3) (6 5) (8 7)
        if(n % (2 * k) != 0) {
            cout << -1 << "\n";
            continue;
        }
        
        // Otherwise we can apply our startegy to each k * 2 interval
        int* a = new int [n];
        for(int i = 1; i <= n; i++){
            a[i-1] = i;
        }
        for(int i = 0; i < n; i += 2 * k){
            swapArray(k, a, i);
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        
    }
    
    return 0;
}
