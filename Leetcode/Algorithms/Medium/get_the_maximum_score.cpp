/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/get-the-maximum-score/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        // We will also partition the arrays into the
        // sums of values between common numbers
        vector<long long> sum1(1, 0);
        vector<long long> sum2(1, 0);

        // The total sum of the path
        long long sum = 0;
        long long mod = 1'000'000'007;

        for(int i = 0, j = 0; i < nums1.size() || j < nums2.size(); ){
            if(i >= nums1.size()){
                // Note that we don't do modulo here,
                // as later on, whether sum1[i] or sum2[i]
                // is larger will become relavant, and 
                // doing modulo can change the correct ordering.
                sum2[sum2.size()-1] += nums2[j];
                j++;
            }
            else if (j >= nums2.size()){
                sum1[sum1.size()-1] += nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]){
                sum2[sum2.size()-1] += nums2[j];
                j++;
            
            else if (nums1[i] < nums2[j]){
                sum1[sum1.size()-1] += nums1[i];
                i++;
            }
            // If they're equal
            else{
                // Since the number is equal,
                // it is common, so it will
                // always be part of the sum,
                sum += nums1[i];
                sum = sum % mod;
                i++;
                j++;

                // We also start a new partition
                sum1.push_back(0);
                sum2.push_back(0);
            }
        }

        // Now we should have the sum
        // of numbers between each common
        // digit, and the sum of the of the
        // common digits themselves.
        // We can now just choose the bigger
        // partition each time.
        for(int i = 0; i < sum1.size(); i++){
            if(sum1[i] > sum2[i]){
                sum += sum1[i];
                sum = sum % mod;
            }
            else{
                sum += sum2[i];
                sum = sum % mod;
            }
        }

        sum = sum % mod;

        return sum;
    }
};