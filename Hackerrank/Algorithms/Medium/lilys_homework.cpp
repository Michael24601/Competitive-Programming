/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/lilys-homework/problem
*/


#include <bits/stdc++.h>

using namespace std;

// A note to make, since we need to minimize |a[i] - a[i]-1|,
// not a[i] - a[i-1], we need the array to be sorted, but
// not necessarily ascending or descending, the absolute value
// means either will work and will be equivalent, so we just
// choose the sort that leads to less swaps.
int main(){
    
    int n;
    cin >> n;
    vector<long> v(n);
    vector<long> u(n);
    vector<long> sortedA(n);
    vector<long> sortedD(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        u[i] = sortedA[i] = sortedD[i] = v[i];
    }
    sort(sortedA.begin(), sortedA.end());
    sort(sortedD.begin(), sortedD.end(), greater<long>());
    // indeces of elements in v and u (works because all elements are distinct)
    unordered_map<long, int> indecesA, indecesD;
    for(int i = 0; i < n; i++){
        indecesA[v[i]] = i;
        indecesD[u[i]] = i;
    }
    
    int swapsA{}, swapsD{};
    for(int i = 0; i < n; i++){
        if(v[i] != sortedA[i]){
            int index = indecesA[sortedA[i]];
            swap(v[i], v[index]);
            swapsA++;
            // Updates indeces just in case
            indecesA[v[i]] = i;
            indecesA[v[index]] = index;
        }
        if(u[i] != sortedD[i]){
            int index = indecesD[sortedD[i]];
            swap(u[i], u[index]);
            swapsD++;
            // Updates indeces just in case
            indecesD[u[i]] = i;
            indecesD[u[index]] = index;
        }
    }
    
    cout << min(swapsA, swapsD);
    
    return 0;
}





