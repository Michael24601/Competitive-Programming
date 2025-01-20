/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/powx-n/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    double myPowAux(double x, long n){
        double r = 1.0;
        for(long i = 0; i < n; i++){
            r*=x;
        }
        return r;
    }

    double myPow(double x, int n) {
        if(x == 1) return 1.0;
        if(n == 0) return 1.0;
        if(x == -1) return (n % 2 == 0 ? 1 : -1);
        if(n > 0) return myPowAux(x, n);
        // If the power is too small, just return 0
        else if(n < -999){
            return 0.0;
        }
        else{ 
            // Because of the way 2s complement negation works,
            // we have 1 more negative number than positive in
            // our range. To account for that, we need to place
            // the int in a long, as the positive of the smallest
            // negative number won't fit.
            long m = n;
            return 1.0 / myPowAux(x, -m);
        }
    }
};