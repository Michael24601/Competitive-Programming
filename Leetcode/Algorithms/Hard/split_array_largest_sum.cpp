/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/split-array-largest-sum/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Checks if splitting is possible with no subarray
    // having more than minimum
    bool isFeasible(vector<int>& nums, int k, int minimum){
        // Sum of subarray up to this point
        int subArraySum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(subArraySum + nums[i] <= minimum){
                subArraySum += nums[i];
            }
            else{
                // Start on a new subarray
                k--;
                subArraySum = nums[i];
            }

            // Used too many subarrays
            if(k == 0){
                return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // This is essentially the book allocation
        // problem.
        // We use a sort of binary search algorithm
        // to solve it.

        // First we define our space:
        // The largest possible max is the whole
        // array
        int max = accumulate(nums.begin(), nums.end(), 0);
        // The smallest max subarray is the largest
        // element since the subarrays have to have one
        // element at least
        int min = *max_element(nums.begin(), nums.end());

        // Then we generate a number mid which is
        // the midpoint of max and min.
        // We know the size of the max subarray 
        // has to be between max and min.
        // So we try to divide the array such that
        // we have k subarrays with a minimum max subarray
        // of mid. If we can, then the actually minimum will
        // be smaller and we set max to mid-1 and repeat.
        // If we can't, the minimum must be larger, and 
        // we can set the min to be mid+1.
        // To check if our mid is feasible, we just
        // partition the array into subarrays of sizes
        // smaller than mid.
        // Basically, from left to right, we continue adding
        // elements to each subarray until they have more
        // than mid, then we switch to the next subarray.
        // If we run out of subarrays, it is not feasible.
        // You'll notice the subarrays all have a roughly
        // the same size (a little less than the minimum
        // of the max). That's because minimizing the max
        // element means making the subarrays as equal as
        // possible.
        while(min <= max){
            int mid = (min + max)/2;
            if(isFeasible(nums, k, mid)){
                max = mid - 1;
            }
            else{
                min = mid + 1;
            }
        }

        return min;
        
    }
};