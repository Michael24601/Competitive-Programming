/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/bigger-is-greater/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int q;
    cin >> q;
    
    while(q--){ 
        string s;
        cin >> s;
        
        for(int i = s.size() - 1; i >= 0; i--){
            int smallest = i;
            for(int j = s.size() - 1; j >= i; j--){
                if(s[j] > s[i] && (smallest == i || s[j] < s[smallest])){
                    smallest = j;
                }
            }     
            if(smallest != i){
                swap(s[i], s[smallest]);
                if(i != s.size() - 1)
                    sort(s.begin() + i + 1, s.end());
                cout << s << "\n";
                break;
            }
            else if(i == 0){
                cout << "no answer\n";
            }
        }    
    }
    
    return 0;
}