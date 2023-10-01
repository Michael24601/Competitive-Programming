/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/longest-valid-parentheses
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string sub) {

        stack<int> c;
        long max{};
        label:
        int size = sub.size();

        // We use a basic stack algorithm for expression vaoidation where we
        // push open parantheses and pop them when we encounter a closed one,
        // but modify it a bit.
        for(int i = 0; i < size; i++){

            // Because we only have one type of parantheses, we don't need
            // to push the character itself, but can instead push its
            // position in the string. This will be useful for later.
            if(sub[i] == '('){
                c.push(i+1);
            } else if (sub[i] == ')'){

                // If we encounter a closed parantheses but the stack is
                // empty, this would mean the expression is invalid. In this
                // problem, it means no part of the string up to this point,
                // no matter how much we cut from tyhe beginning, can be
                // contribute to the longest substring if it exists after
                // this point (it might not), so we empty the stack (already
                // is empty), and repeat the algorithm for the next character.
                // Note that we restart i from 0, since the position of the
                // open parantheses pushed to the stack needs to be in relation
                // to where we count the start from.
                if(c.empty()){
                    sub = sub.substr(i+1);
                    goto label;
                }
                else{
                    c.pop();
                }
            }
            
            // If we reach the end of an iteration, we can have an empty
            // stack, which means we have an equal number of matching
            // paranthesis in the right order up to this point, so we 
            // can assume the string up to now is valid, and make it the max
            // if it is the largest it has been. Otherwise, it means we have
            // some open parantheses we haven't yet closed. The string is
            // only valid after the last one pushed, so we use the position
            // of the top element to calculate the length of the remaining
            // expression after the last parantheses up to this point.
            if(c.empty()){ 
                if(i+1 > max) 
                    max = i+1;
            }
            else{
                if(i+1 - c.top() > max)
                max = i+1 - c.top();
            }
        }
        return max;
    }
};