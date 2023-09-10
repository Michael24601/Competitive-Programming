/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/electronics-shop/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b, n, m;
    cin >> b >> n >> m;

    vector<int> k;
    k.resize(n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }
    
    vector<int> l;
    l.resize(m);
    for(int i = 0; i < m; i++){
        cin >> l[i];
    }
    
    sort(l.begin(), l.end());
    sort(k.begin(), k.end());
        
    int max = -1;
    for(int i = 0; i < n; i++){
        if(k[i] >= b){
            break;
        }
        else{
            int var = 0;
            for(int j = 0; j < m ; j++){
                if(l[j] + k[i] <= b){
                    var = l[j] + k[i];
                }
                else{
                    break;
                }
            }
            if(var != 0 && max < var){
                max = var;
            }
        }
    }
    
    cout << max;

    return 0;
  
}