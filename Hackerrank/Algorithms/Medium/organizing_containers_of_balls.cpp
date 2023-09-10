/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<long> ballsPerContainer(n, 0);
        vector<long> ballsPerColor(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                long c;
                cin>>c;
                ballsPerContainer[i]+=c;
                ballsPerColor[j]+=c;
            }
        }

        sort(ballsPerColor.begin(), ballsPerColor.end());
        sort(ballsPerContainer.begin(), ballsPerContainer.end());

        bool possible = true;
        for(int i = 0; i < n; i++){
            if(ballsPerContainer[i] != ballsPerColor[i]){
                possible = false;
               break;
            }
        }
        if(possible) cout << "Possible\n";
        else cout << "Impossible\n"; 
    }
}