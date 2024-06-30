/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/jump-game/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // We can use dynamic programming. We can create an array p,
        // where p(k) is true if and only if we can get to index k from
        // index 0. However, checking all indexes that we can get to from
        // each index, it would have the time complexity O(n^2).
        // The greedy solution is to instead always go to the index that
        // can get the closest to the finish line, meaning that we want
        // to minimize the value distance from k to last digit - nums[k]
        // (distance left - range we can cover from k).
        // If the distance is negative or 0, we immediatly return true,
        // as we can reach the end.
        // Since the jump distance is the max we can jump, and doesn't have
        // to be that number exactly, the element with the most range
        // will be the best always, which is why the greedy algorithm works.
        // The time complexity is on average O(n) since we always move forward
        // and go the furthest we can.

        if(nums.size() == 1) return true;

        int lastIndex = nums.size() - 1;

        // This check is only added for the first case
        // since it won't be done like the other indexes.
        if(nums[0] >= lastIndex) return true;

        for(int i = 0; i < nums.size(); ){   
            int minIndex = -1, min = 999'999;
            for(int j = i+1; j <= i + nums[i]; j++){
                int v = (lastIndex - j) - nums[j];
                if(v <= 0) return true;
                else if (v < min) {
                    min = v;
                    minIndex = j;
                }
            }
            i = minIndex;
        }

        return false;
    }
};