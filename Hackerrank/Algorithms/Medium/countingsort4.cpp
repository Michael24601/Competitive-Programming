/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/countingsort4/problem
*/


#include <bits/stdc++.h>

using namespace std;

struct element{
    string s;
    int value;
    // Original label used both for '-' replacement at the end and for
    // deciding which comes first during the sort.
    int originalIndex;
};

// Since I am using c++, there is no need to implement my own
// sorting algorithm, all I have to do is write a comparison
// function and send it as an argument to sort (lambda function)
int main(){
    int n;
    cin >> n;
    vector<element> v(n);
    for(int i = 0; i < n; i++){
        int a;
        string s;
        cin >> a >> s;
        v[i] = {s, a, i};
    }
    sort(
        v.begin(), 
        v.end(), 
        [](element& s1, element& s2)->bool{ 
            if(s1.value == s2.value){
                return s1.originalIndex < s2.originalIndex;
            }
            return s1.value < s2.value;
        }
    );   
    
    for(auto &a: v){
        if(a.originalIndex < n/2){
            cout << "- ";
        }
        else{
            cout << a.s << " ";
        }
    }
    
    return 0;  
}