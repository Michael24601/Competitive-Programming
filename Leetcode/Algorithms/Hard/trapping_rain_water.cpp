/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/trapping-rain-water/
*/


#include <bits/stdc++.h>

using namespace std;

// At each index, we need to know the how long the largest 
// columns to the left and right are. The amount of water
// above it will be the minimum between the difference in
// height with the left, and the difference in height with the 
// right granted both are positive
// We can do this in two passes, in the first we store the info in two
// vectors, one for the maxLeft and the other for the maxRight,
// then do another pass to sum the rainwater volume (O(n) space 
// and time). But we can instead have a space complexity of O(1)
// and do everything in just one pass, which is what we should do.
// At each step we add the minimum of the two, so we need to find a
// loop that ensures that when we subtract from maxLeft or maxRight,
// either one is the minimal of the two. 
// With an index called right and one called left, left inches forward 
// when height[left] < height[right] and right inches backwards when the
// opposite is true. Then, if height[left] is smaller than height[right],
// we add the discussed difference maxLeft - height[left] to the total,
// as doing height[left] < height[right] guarantees that at any given 
// point we're adding maxSide - heigh[side], the maxSide is smaller
// than the maxOtherSide, emulating the min we used in the naive approach.

// Here is the very clear 2 passes code:
/*
    // Left pass and right pass
    int maxLeft = height[0], maxRight = height[height.size()-1];
    vector<int> left(height.size());
    vector<int> right(height.size());
    for(int i = 0; i < height.size(); i++){
        // left pass
        if(height[i] > maxLeft){
            maxLeft = height[i];
        }
        else {
            left[i] = maxLeft - height[i];
        }

        // right pass
        if(height[height.size() - i - 1] > maxRight){
            maxRight = height[height.size() - i - 1];
        } else {
        right[height.size() - i - 1] 
            = maxRight - height[height.size() - i - 1];
    }
    long long total{};
    for(int i = 0; i < height.size(); i++){
        total += min(left[i], right[i]);
    }
    return total;
*/

// And this is the efficient solution (same time complexity though)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        int total = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    total += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] > maxRight) {
                    maxRight = height[right];
                } else {
                    total += maxRight - height[right];
                }
                right--;
            }
        }

        return total;
    }
};
