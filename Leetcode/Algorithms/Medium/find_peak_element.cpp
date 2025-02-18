/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/find-peak-element/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
    
            // We can pad nums with -infinity in order to remove
            // special cases.
            int limit = numeric_limits<int>::min();
            nums.push_back(limit);
            nums.insert(nums.begin(), limit);
    
            // We can use a modified binary search
            // (ignoring the padded limits).
            // If nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1], 
            // we have our answer.
            // If nums[mid] < nums[mid+1], then then next number is larger
            // so we go to the second half for a peak.
            // If nums[mid] < nums[mid-1], then then previous number is larger
            // so we go to the first half for a peak.
            // if nums[mid] is smaller than both, there will be a peak in
            // either half.
            int begin = 1;
            int end = nums.size() - 2;
    
            while(begin <= end){
                cout << begin << " " << end << "\n";
                int mid = (begin + end)/2;
    
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    // mid - 1 because recall we padded the array
                    return mid - 1;
                }
                else if (nums[mid] < nums[mid+1]){
                    begin = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
    
            // Impossible to get here
            return 0;
        }
    };