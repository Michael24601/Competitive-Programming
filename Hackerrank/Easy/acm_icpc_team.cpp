/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/acm-icpc-team/problem
*/


#include <bits/stdc++.h>

using namespace std;

int known(string s1, string s2){
    int count = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == '1' || s2[i] == '1'){
            count++;
        }
    }
    return count;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> inputs(n);
    int mt = 0;
    for(int i = 0; i < n; i++){
        string c;
        cin >> c;
        inputs[i] = c;
    }
    
    int max = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            int num = known(inputs[i], inputs[j]);
            if(num > max){
                max = num;
                mt = 1;
            }
            else if (num == max){
                mt++;
            }
        }
    }
    
    cout << max << "\n" << mt;
}