/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/almost-sorted/problem
*/


#include <bits/stdc++.h>

using namespace std;

// Returns the different indeces between two arrays, one of which
// is the sorted version of the other.
// If the size is 2, then we can sort the array with a swap,
// otherwise, if 0, it is already sorted. If the size is larger than
// 2, then we need to make sure the indeces are contiguous, and
// that the elements are sorted in reverse order.
vector<int> diff(vector<int>& a, vector<int>& b){
    vector<int> c;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) c.push_back(i); 
    }
    return c;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> sorted(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sorted[i] = v[i];
    }
    
    sort(sorted.begin(), sorted.end());
    
    vector<int> c = diff(v, sorted);
    if(c.size() == 0){
        cout << "yes";
    }
    else if (c.size() == 2){
        cout << "yes\nswap " << c[0]+1 << " " << c[1]+1;
    }
    else{
        // Make sure it's reverse ordered
        for(int i = c[0]+1; i <= c[c.size() - 1]; i++){
            if(v[i] > v[i-1]){
                cout << "no";
                return 0;
            }
        }
        cout << "yes\nreverse " << c[0]+1 << " " << c[c.size() - 1]+1;
    }
    
    return 0;
}
