/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/big-sorting/problem
*/


#include <bits/stdc++.h>

using namespace std;

// We create a new comparison function to treat strings like
// numbers. If their size is different, the longer is bigger,
// otherwise use standard string compare
bool compare(string& s1, string& s2){
    if(s1.size() > s2.size()){
        return false;
    }
    else if (s1.size() < s2.size()){
        return true;
    }
    else return s2.compare(s1) > 0;
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), &compare);
    
    for(int i = 0; i < n; i++){
        cout << v[i] << "\n";
        
    }
    
    return 0;
}
