/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/remove-invalid-parentheses/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // Checking valid parantheses using a stack
    bool validPara(string& s){
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(1);
            }
            else if (s[i] == ')'){
                if(st.empty()){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    vector<string> removeInvalidParentheses(string s) {

        // We will use backtracking to remove every parantheses
        // possible.
        // We want to at each level of the computation to branch out
        // by removing one of each parantheses in the string.
        // If at level x, which is denoted by the variable x,
        // we find a solution, then we can stop all computations
        // at level x+1 (as they are not optimal solutions).
        // So we need breadth first search, not depth first.

        // Queue for BFS
        queue<string> q;
        // Largest size string we found valid
        int n = 0;
        // Solutions (set to avoid duplicates)
        vector<string> sol;

        // We also have a visited set to ensure the queue
        // never visits the same set twice
        // Which also ensures the solutions are all unique
        // too.
        unordered_set<string> visited;
        
        q.push(s);
        while(!q.empty()){
            string t = q.front();
            q.pop();
            // We already found a better solution
            // so we can break as we are done
            // BFS ensures all strings of the same
            // size are done first).
            if(t.size() < n){
                break;
            }
            else if(validPara(t)){
                sol.push_back(t);
                n = t.size();
            }
            // Else we push back the strings the queue
            // to backtrack, with one character removed
            else{
                for(int i = 0; i < t.size(); i++){
                    // Only remove parantheses
                    if(t[i] == ')' || t[i] == '('){
                        string u = t;
                        u.erase(i, 1);
                        if(visited.find(u) == visited.end()){
                            visited.insert(u);
                            q.push(u);
                        }
                    }
                }
            }
        }

        return sol;
    }
};