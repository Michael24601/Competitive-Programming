/*
    Website: Leetcode
    Difficulty: Easy
    Language: c++
    Link: https://leetcode.com/problems/find-the-town-judge/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // We can create two vectors, trusts and trusted,
        // where trust[i] is the number of people person i trusts,
        // and trusted[i] is the number of people who trust i.
        // The judge must have the former be 0, and the latter be n-1.

        vector<int> trusts(n, 0);
        vector<int> trusted(n, 0);

        for(int i = 0; i < trust.size(); i++){
            // The -1 accounts for the 0-index
            trusts[trust[i][0]-1]++;
            trusted[trust[i][1]-1]++;
        }

        for(int i = 0; i < n; i++){
            if(trusts[i] == 0 && trusted[i] == n-1){
                // The +1 accounts for the 0-index
                return i + 1;
            }
        }

        return -1;
    }
};