/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/word-ladder/
*/


#include <bits/stdc++.h>


class Solution {
public:

    // Retunrs how many chars are different.
    // Assumes s1 and s2 have the same length
    int difference(string& s1, string& s2){
        int c = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                c++;
            }
        }
        return c;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Because we only have 5000 words, with max length 10, 
        // we can easily loop over every word as we change each letter.
        // Every step, we visit all words in wordlist that are one 
        // char difference from beginWord.
        // We maintain a list of visited words so we never have to visit
        // any word twice and enter a loop.
        // The first time we reach endWord, we retur the depth, which is the
        // number of steps needed.
        // Otherwise if we never find endWord and we can't visit any more
        // unvisited words, we stop abd return 0 (impossible).
        // The reason w ejust BFS not DFS is that when endWord is reached in
        // BFS, the depth we're at is the answer (shortest sequence),
        // but in DFS we'll need to do all possible sequences that reach
        // endWord before we can be sure which is the shortest.

        unordered_map<string, bool> visited;
        vector<string> current{beginWord};

        int depth = 0;
        while(true){

            // The words that we will check next depth
            vector<string> newCurrent;

            for(int j = 0; j < current.size(); j++){
                for(int i = 0; i < wordList.size(); i++){
                    if(
                        !visited[wordList[i]]
                        && difference(current[j], wordList[i]) == 1
                    ){
                        if(wordList[i] == endWord){
                            // Depth + 2 which is the begin and end words
                            return depth+2;
                        }
                        else{
                            visited[wordList[i]] = true;
                            newCurrent.push_back(wordList[i]);
                        }
                    }
                }
            }

            // Means we can't visit new words, so we're stuck
            if(newCurrent.size() == 0){
                return 0;
            }
            else{
                depth++;
                current = newCurrent;
            }
        }

    }
};