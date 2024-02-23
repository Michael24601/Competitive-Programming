/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/permutation-sequence/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getPermutation(long n, long k) {

        // We know the first number repeats itself in sequences
        // of (n-1)! times.
        // So to get k, we can scroll to the smallest value
        // of a such that a*(n-1)! is smaller than k.
        // We can use integer division by (n-1)! for that.
        // We can then repeat this step for each character,
        // as it will follow (not however that the character's orders)
        // changes. For instance, if the first char is 2 for n = 4,
        // the rest of the pattern follows that of 123 (n = 3)
        // but with 134 instead of 123.
        // For example, for n = 3 and k = 3,
        // We know that the first rank is 2 (3 is between 3 and 4 and each
        // rank is 2! = 2 big), so the first number will be 2.
        // We repeat this step for n = 2, so now we have k-2 = 1 left,
        // and that puts us in the first rank of the digits, 
        // which are 12, but we already removed 2, so in reality we have
        // 13, which means the second digit is 1.
        // We can keep trasck of which digits have been removed by 
        // using a string 123, and removing the character at the current
        // rank's index. Thre resulting string is always the remaining
        // indeces, since removing any character actually keeps them sorted. 

        // Quickest way to store factorials up to 10!
        long fa[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 
        362880ll, 3628800ll};

        string s = "", result = ""; 
        for(int i = 1; i <= n; i++){
            s += to_string(i);
        }

        // k is given with index starting at 1, but we want it at 0
        k = k-1;
        while(n > 0){
            long rank = k / fa[n-1];
            long traversed = fa[n-1] * rank;
            k -= traversed;
            n--;

            // For each rank we get
            result += s[rank];
            s.erase(rank, 1);
        }

        return result;
    }
};
