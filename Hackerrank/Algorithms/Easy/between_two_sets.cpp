/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/between-two-sets/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int minA = *min_element(a.begin(), a.end());
    int maxB = *max_element(b.begin(), b.end());
    
    int count{};
    
    for(int i = minA; i <= maxB; i++){
        bool accepted = true;
        for(int j = 0; j < a.size(); j++){
            if(i %a[j] != 0){
                accepted = false;
                break;
            }
        }
        if(accepted){
            for(int k = 0; k < b.size(); k++){
                if(b[k] % i != 0){
                    accepted = false;
                    break;
                }
            }
        }
        if(accepted){
            count++;
        }
    }

    cout << count;
    
    return 0;
}
