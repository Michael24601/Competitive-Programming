/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/manasa-and-stones/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        vector<int> v;
        cin >> n >> a >> b;

        // Since we only care about the final sum, and not the order,
        // we always order the stones in the same way, and combine them
        // in such a way as we start with n of the smaller distance stones,
        // and incrementely switch them for the larger ones, until we have
        // n larger distance stones, ensuring our result is ascending.
        // Along the way we ensure we have no repeated sums.
        // This code first makes sure a is the larger and be the smaller.
        int temp = min(a, b);
        a = max(a, b);
        b = temp;
        n--;
        for(int i =0; i <= n; i++){
            int m = i * a + (n-i) * b;
            if(find(v.begin(), v.end(), m) == v.end()){
                v.push_back(m);
                cout << m << ' ';  
            }
        }
        cout << '\n';
    }
    return 0;
}