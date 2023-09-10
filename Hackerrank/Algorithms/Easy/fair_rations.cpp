/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/fair-rations/problem
*/


#include <bits/stdc++.h>

using namespace std;

// If we have an odd number of odd bread count, it's a no.
// This is because any bread giving will flip 2 numbers,
// so the pairity is an invariant.
// so for there to be 0 odd bread at the end, we need 
// an even number of odd breads at the start (since 0 is even).

// Our startegy will be to always flip the right bread if we
// have to. Since we always have an even number of odd breads,
// (we quit early otherwise),
// We never arrive at a point where we only have 1 odd bread
// on the right. So when we reach n-1, either both are even or
// both are odd. The loop invariant also ensures that all
// breads on the left are even since we never flip those (and we
// start from the left).
int main() {
    
    int n;
    cin >> n;
    vector<int> B(n);
    
    // Keeps track of even and odd numbers of bread
    int odd{};
    int even{};
    for(int i = 0; i < n; i++){
        cin >> B[i];
        if(B[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    if(odd % 2 == 1){
        cout << "NO";
    }
    else{
        int n = 0;
        // As per the algorithm, we stop at n-1
        // Since either both are even, or both are odd.
        // The former is already resolved and the latter is
        // resolved by flipping the second to last person, but
        // we never have to touch the last person.
        for(int i = 0; i < B.size() - 1; i++){
            if(B[i] %2 == 1){
                B[i]++;
                B[i+1]++;
                n+=2;
            }
        }
        cout << to_string(n);
    }

    return 0;
}
