/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/minimum-window-substring/
*/


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        
        // What we can do is initialize a hashmap to count the frequency
        // of each character in the window we currently have,
        // as well as a hashmap for the needed frequency, which we can
        // compare to see if window is valid.
        // We start with the window having size 0 and then expanding
        // right-ward in s, adding one char to the window each time,
        // and updating the frequency.
        // Everytime we move right, we can check to see how many chars we
        // can remove from the left side, which is only allowed if we already
        // have more than is needed.
        // After both of those steps, we check to see if window is valid.
        // If yes, check size, and if smaller than the last valid window,
        // save its size and contents. Continue until we move as right
        // as possible while shaving off from the left as much as possible.
        // Then return the minimum window.

        unordered_map<char, int> needed;
        unordered_map<char, int> window;
        int left = 0, right = 0;

        for(int i = 0; i < t.size(); i++){
            needed[t[i]]++;
        }

        // It is impossible for the window to be bigger than s
        // so it is used as upper bound
        int smallestSize = s.size();
        string smallest = "";

        for(int i = 0; i < s.size(); i++){
            // Add one letter on the right
            right = i;
            window[s[i]]++;
            
            // We then remove all we can remove from the left
            for(int j = left; j <= right; j++){
                if(window[s[j]] > needed[s[j]]){
                    left++;
                    window[s[j]]--;
                }
                // Once we can't remove a char, we just stop checking,
                // as we have to remove a continuous substring
                else{
                    break;
                }
            }

            // Check if window is valid and record size
            bool wrong = false;
            // Lower and upper case
            for(char a = 'a', A = 'A'; a <= 'z'; a++, A++){
                if(window[a] < needed[a]){
                    wrong = true;
                    break;
                }
                if(window[A] < needed[A]){
                    wrong = true;
                    break;
                }
            }

            if(!wrong){
                if(right - left + 1 <= smallestSize){
                    smallestSize = right - left + 1;
                    smallest = s.substr(left, right - left + 1);
                }
            }

        }

        return smallest;
    }
};