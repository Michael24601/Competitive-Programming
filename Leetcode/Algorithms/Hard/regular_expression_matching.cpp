/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/regular-expression-matching/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool NFA(string& s, string& p, int buildSize = 0, char newChar = '$', int i = 0){

        // We have two choices: we can build a string literally and
        // send it by value each time we make a call, then check if the
        // initial substring of s matches the built string at the start of
        // each call (and return false otherwise).
        // However, as we are checking the built string at each recursive
        // call, we will know that the built string will match the
        // start of s, with the exception of the last added character.
        // So in reality, we only need to send the last added character
        // and the built string size up to this point.
        // If no character was added in a particular call (such as the first
        // or when we consider * to have added no characters, we send
        // the last added character (since the buildSize didn't change,
        // the macth will still be correct).
        // Initially when the function is called a random character is sent;
        // it won't make a difference since the buildSize is 0, so we don't
        // yet need to check for matches.

        // Ignoring the initial call since no characters have been added
        if(buildSize > 0 && s[buildSize-1] != newChar){
            return false;
        }

        // If we have arrived at the end of the pattern, we simply check
        // if the built string and s have the same size.
        // Since we have already checked for matches in characters up to this
        // point, if they have the same size, they are the same string, and
        // since the pattern is done, the built string is done too.
        if (i == p.size()){
            return buildSize == s.size();
        }
        // If we aren't at the end of the pattern and 
        // the built string is longer than s, 
        // then it can never be the same as s.
        if (buildSize > s.size()){
            return false;
        }

        if (i < p.size() - 1 && p[i+1] == '*'){
            // If there is a star after this character, we just skip
            // and handle the star case.
            // We send the same buildSize and newChar as the last call.
            return NFA(s, p, buildSize, newChar, i+1);
        }
        else if(p[i] == '.'){
            // Creating a case for each letter, and returning true
            // if any of them return true.
            bool n = false;
            for(char c = 'a'; c <= 'z'; c++){
                n = n || NFA(s, p,  buildSize + 1, c, i+1);
            }
            return n;
        }
        else if (p[i] == '*'){
            // We can simulate the behavior of * by doing something like this:
            // abc*d generates two built strings: ab and abc,
            // the first one then increments i so we movr away from *,
            // and the second case doesn't, so we have the option of repeating
            // this step again (if the built string still matches the start of s).
            // This won't recuse forever since the built string still needs
            // to match the beginning of s at each repeated call.
            // Note that one possible imporvement is instead of creating a branch
            // for each letter, to only create one branch for the letter we know
            // comes next. It is however easier and more streamlined to handle
            // character matching in one place at the start of the function call.

            bool n = false;
            // First case
            // We send the same buildSize and newChar as the last call.
            n = n || NFA(s, p,  buildSize, newChar, i+1);
            // Second case
            if(p[i-1] == '.'){
                for(char c = 'a'; c <= 'z'; c++){
                    n = n || NFA(s, p,  buildSize + 1, c, i);
                }
            }
            else{
                n = n || NFA(s, p,  buildSize + 1, p[i-1], i);
            }
            return n;
        }
        else{
            return NFA(s, p, buildSize + 1, p[i], i+1);
        }
    }

    bool isMatch(string s, string p) {
        
        // Since regular expressions are just finite automata,
        // we can simulate the behavior of a nondeterministic finite
        // automaton by building the string that the pattern p can detect
        // from the ground up. We create branches where more than one possibility
        // is available (steeming from * introducing multiple possibilities for
        // length), and we end a branch when it no longer matches the substring
        // of s of the same length. We return true if at least one branch matches s
        // once it has already reached the end of p.
        // The reason we use recursion is because we want to simulate
        // parrallelism (branching). Deterministic and Nondeterministic
        // Finite Automata are equivalent, so we can simulate the latter by
        // having each of the n states in the NFA become one of the 2^n
        // states of the DFA representing a subset of states that may be
        // active at any step of the input (the pattern p in our case).
        // This going from n to 2^n is what gave me the idea of using 
        // a tree (aka recursion) to simulate the branching in an NFA.

        return NFA(s, p);
    }
};