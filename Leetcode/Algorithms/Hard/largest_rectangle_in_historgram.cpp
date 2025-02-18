/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Any rectangle area contains a column
        // whose height determines the height of the column,
        // meaning the shortest column.
        // This applies to the largest rectangle as well.
        // Given a column, we can determine the largest rectangle
        // area such that it is the shortest column in it;
        // we know its the rectangle that starts after the last
        // shorter column and ends before the next shorter
        // column (or the boundarier if no column is shorter).
        // We can calculate this value for each column then pick
        // the max.

        // Index of the start rectangle
        vector<int> prevS(heights.size());
        // Index of the end rectangle
        vector<int> nextS(heights.size());

        // Stack used in the algorithm
        // Contains index of the last (or next)
        // shorter column
        stack<int> stack;

        // First for prev runs in O(n)
        for (int i = 0; i < heights.size(); ++i) {
            // Basically, if the stack is empty, the last
            // smallest element is the first.
            // If not empty, we check if teh top of the stack
            // is higher; if it is, we need to pop until we reach a
            // shorter top of we have an empty stack.
            // When we have a shorter element, the element after
            // it is the start of the rectangle.
            // We then finally push the current index on the stack.

            // Note that the stack allows us to do this in O(n)
            // because, for example, if we know that heights[i]
            // has some previous shorter column index, it will be
            // on the stack top, right below the index i.
            // We can then check height[i+1] against height[i].
            // If it is smaller, we take i, else we pop, and we use i's
            // solution, which is now at the top of the stack,
            // as none of the indexes between i+1 and it will count,
            // as they were higher than height[i], and therefore
            // higher than height[i+1].
            // This ensures each element is popped at most once from
            // the stack, making the time complexity linear.
            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }
            if(stack.empty()){
                prevS[i] = 0;
            }
            else{
                prevS[i] = stack.top() + 1;
            }
            stack.push(i);
        }

        // We can reuse the same stack
        while (!stack.empty()) {
            stack.pop();
        }

        // We then do the same for next
        for (int i = heights.size() - 1; i >= 0; --i) {
            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }
            if(stack.empty()){
                nextS[i] = heights.size() - 1;
            }
            else{
                nextS[i] = stack.top() - 1;
            }
            stack.push(i);
        }

        // Now, the area of the rectangles described is the width
        // which can be calculated as the difference between prev
        // and nex for each index, times height[i] at the column
        // for which the rectangle is defined. 
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int area = (nextS[i] - prevS[i] + 1) * heights[i];
            if(area > maxArea){
                maxArea = area;
            }
        }

        return maxArea;
    }
};