/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/happy-ladybugs/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int g;
    cin >> g;
    while(g--){
        int n;
        cin >> n;
        string b;
        cin >> b;
        
        if(b.length() == 1){
            if(b[0] == '_')
                 cout << "YES\n";
            else
                // Single colored ladybug can never be happy
                cout << "NO\n";
            continue;
        }
        
        // First check if all ladybugs are happy
        bool allHappy = true;
        for(int i = 0; i < b.length(); i++){
            // We don't care if the tile is empty (if it has similar
            // adjacent tiles)
            if(b[i] == '_'){
                continue;
            }
            // We already know at that we have at least 2 elements,
            // so we don't need to check if b[1] and b[i-1] exist.
            else if(i == 0 && b[0] != b[1]){
                allHappy = false;
                break;
            }
            else if(i == b.length() - 1 && b[i] != b[i-1]){
                allHappy = false;
                break;
            }
            // Middle case, if we reach it we can assume b[i-1] an b[i+1]
            // exist.
            else if(b[i] != b[i-1] && b[i] != b[i+1]){
                allHappy = false;
                break;
            }
        }
        
        if(allHappy){
            cout << "YES\n";
            continue;
        }
        
        // If not all ladybugs are happy, then we can make them happy
        // if and only if there is at least one empty space and if 
        // all colors that occur, occur at least twice.
        bool empty = false;
        map<int, int> m;
        for(int i = 0; i < b.length(); i++){
            if(b[i] == '_'){
                empty = true;    
            }
            else{
                m[b[i]]++;
            }
        }
        if(!empty){
            cout << "NO\n";
            continue;
        }
        
        bool alone = false;
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second == 1){
                cout << "NO\n";
                alone = true;
                break;
            }
        }
        if(!alone){
            cout << "YES\n";
        }
    }
    return 0;
}
