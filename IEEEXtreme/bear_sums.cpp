
#include <bits/stdc++.h>

using namespace std;

int main(){

    short t;
    cin >> t;

    while(t--){

        int sum;
        cin >> sum;
        int e;
        cin >> e;

        unordered_map<int, int> map;
        int* a = new int[e];

        for(int i = 0; i < e; i++){
            int c;
            cin >> c;
            a[i] = c;
            map[c]++;
        }
        bool found = false;
        for(int i = 0; i < e && !found; i++){
            int complement = sum - a[i];
            if(map.count(complement)){
                cout << min(a[i], complement)
                << " " << max(a[i], complement) << "\n";
                found = true;
            }
        }
        if(!found){
            cout << "!OK\n";
        }
    }

    return 0;
}