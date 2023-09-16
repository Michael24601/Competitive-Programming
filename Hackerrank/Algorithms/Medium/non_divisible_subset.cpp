/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/non-divisible-subset/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long n, k;
    cin >> n >> k;   
    vector<long> v(k, 0);
    long sum = 0;

    // Records in the vector the number of elements with each modulo class of k
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        v[c%k]++;
    }
    
    int mid = (v.size() % 2 == 0 ? v.size()/2 : v.size()/2 + 1);
    
    // We need the (not necesarily successive) subset of the above array
    // where all pairs of numbers summed aren't divisible by k.
    // For each modulo class i, the only numbers that, when summed with them,
    // make a number divisible by k are members of the modulo class (k-i),
    // so we can have either but not both in our subset. We choose the larger.
    // Note that we do this up to the middle, and don't check after that
    // cause then we reach the same modulo classes and repeat them. 
    // This does not apply for the modulo class n/2 or 0, for reasons 
    // explained later.
    for(int i = 1; i < mid; i++){
        sum += max(v[i], v[k-i]);
    }
    
    // However, if n is even, then there is a modulo class n/2, where
    // the sum of members in that class is divisible by k, because i = k-i.
    // In this case, we can only have 1 number from this modulo class (if there
    // is one). 
    if(v.size() % 2 == 0 && v[v.size()/2] >= 1){
        sum++;
    }
    // Likewise, if i % k == 0, k divides i already, so we can only include
    // one of these, since adding them together also gives a number divisible
    // by k (but summed with any other number doesn't).
    if(v[0] >= 1){
        sum++;
    }

    cout << sum;
    
    return 0;
}
