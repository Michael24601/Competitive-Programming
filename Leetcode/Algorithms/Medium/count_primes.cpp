
/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/count-primes/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        // We can use the Siece of Eratosthenes
        // We know that every composite number can be written
        // in the form p * m where m is any number > 1,
        // and p is a prime.
        // So, one way to find all primes is to do this:
        // Start with prime p = 2:
        // calculate each of 2p, 3p, 4p, 5p...
        // Until we reach n.
        // The smallest number not included, k, has to be
        // the next prime.
        // Why? Because we know that there are infinite
        // primes, so p is not the only prime left,
        // so there must be another prime, and since
        // no prime q larger than k can be written such
        // that k = qm where m > 1, q must itself be
        // the next prime.
        // So we repeat the algorithm with p = q,
        // until we have a p larger than n.

        if(n <= 2) return 0;

        // Vector where vec[i] indiciates if i number
        // is marked or no:
        // We start with no marks.
        vector<bool> vec(n+1, false);
        int primeCount = 1;
        int p = 2;
        
        // This is O(n log(n) log(n))
        while(p < n){

            for(int i = 2; p * i <= n; i++){
                vec[p * i] = true;
            }

            // We then find the next smallest unmarked
            // number
            do{
                p++;
            }while(p < n && vec[p]);

            if(p < n){
                primeCount++;
            }
        }

        return primeCount;
    }
};