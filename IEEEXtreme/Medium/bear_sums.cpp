/*
    Website: IEEEXtreme
    Difficulty: Medium
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/bear-sums
*/


#include <bits/stdc++.h>

using namespace std;

struct Triplet {
    int first;
    int second;
    int third = 0;
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int s, e;
        cin >> s >> e;
        vector<int> v(e);
        // Maps each value to count and earliest two indeces.
        // We will see why we need the earliest two later.
        unordered_map<int, Triplet> count;
        
        if(e == 0){
            cout << "!OK\n";
            continue;
        }
        
        for(int i = 0; i < e; i++){
            int a;
            cin >> a;
            v[i] = a;
            if(!count.count(a))
                count[a].first = i;
            // second earliest
            else if(count[a].third == 1)
                count[a].second = i;
            // Always increment the count
            count[a].third++;
        }
       
        // We need the earliest pair with a sum of 6.
        // We can do this by storing in the min map position
        // of a complement pair, which is the index of the later 
        // of the two complements.
        // The reason we save the earliest two indeces is in the,
        // case of the number being its own complement
        int minimum{99999999};
        int number{};
        for(int i = 0; i < e; i++){
            // If complement is the number itself, we need at least 2 of them
            if(s - v[i] == v[i] && count.count(v[i]) && count[v[i]].third > 1){
                if(minimum > count[v[i]].second){
                    minimum = count[v[i]].second; // Later index
                    number = v[i];
                }
            }
            else if(count.count(s - v[i]) && s - v[i] != v[i]){
                if(minimum > max(count[v[i]].first, count[s-v[i]].first)){
                    // Also Later index
                    minimum = max(count[v[i]].first, count[s-v[i]].first);
                    number = v[i];
                }
            }
        }
        if(minimum == 99999999){
            cout << "!OK\n";
        } else {
            cout << min(number, s - number) << " " << max(number, s-number) << "\n";
        }
    }
}