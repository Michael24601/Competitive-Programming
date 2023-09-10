/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/apple-and-orange/problem
*/


#include <bits/stdc++.h>

using namespace std;

void countApplesAndOranges(int s, int t, int a, int b,
    vector<int>& apples, vector<int>& oranges) {
    
}

int main() {
    int s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;
    
    int app=0;
    int ora = 0;
    for(int i = 0; i < m; i++){
        int apple;
        cin >> apple;
        if(apple + a >= s && apple + a <= t){
            app++;
        }
    }
    for(int i = 0; i < n; i++){
        int orange;
        cin >> orange;
        if(orange + b >= s && orange + b <= t){
            ora++;
        }
    }
    cout << app << "\n" << ora;

    return 0;
}
