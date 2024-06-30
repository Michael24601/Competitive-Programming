/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/word-search/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    // Since the input sizes are pretty small, we can just brute
    // force it with a depth first search.
    // In this recursive function, at any given point,
    // we know which entry we are at in the matrix and the index of
    // the word that we are at (which char).
    // We can then explore all possible branches that we can go to
    // such that the next letter we go to is the next letter in the word.
    // If any branch arrives at the full word, true is returned. If
    // all branches return false, false is returned.
    
    bool recursive(
        int currentY, int currentX, int currentIndex, 
        vector<vector<char>>& board, string& word
    ){

        int OneDCoordinate = currentY * board[0].size() + currentX;

        // First we check that the coordinate we are at exists.
        if(currentY < 0 || currentY >= board.size()
        || currentX < 0 || currentX >= board[0].size()){
            return false;
        }
        // Then we ensure the entry matches the word letter at this index
        else if (word[currentIndex] != board[currentY][currentX]) {
            return false;
        }
        // If it fits all criteria, and it is the last letter of the word,
        // we return true.
        else if (currentIndex == word.size() - 1){
            return true;
        }
        // Else, we just check all 4 directions we can go to, and return
        // true if any of them is true. We also add this entry to the list
        // of used entries.
        else{

            // We can use an unordered set to keep track of which entries
            // have already been used, then send it by reference.
            // We would add each entry to the set when used, then remove it
            // before exitting the recursive function. If we ever enter an entry
            // we've used already, we can return false. This is a bit too slow
            // however. We can simulate the behavior by changing every used
            // entry to some non-letter char like $, then return it to normal
            // when we exit the recurive function.
            // This is much faster as there is no need to check, insert, and
            // remove on an unordered set.

            char val = board[currentY][currentX];
            board[currentY][currentX] = '$';

            bool returnValue = (
                recursive(currentY, currentX - 1, currentIndex + 1, board, word)
                || recursive(currentY, currentX + 1, currentIndex + 1, board, word)
                || recursive(currentY - 1, currentX, currentIndex + 1, board, word)
                || recursive(currentY + 1, currentX, currentIndex + 1, board, word)
            );
            
            board[currentY][currentX] = val;

            return returnValue;
        }
    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(recursive(i, j, 0, board, word)){
                    return true;
                }
            }
        }
        return false;
    }


    // This here is the previous solution with an unordered set, which
    // is too slow.
    
    /*
    bool recursive(
        int currentY, int currentX, int currentIndex, 
        vector<vector<char>>& board, string& word,
        // We use a set to keep track of which entries have already been
        // used, by saving the 2D coordinate in its 1D form
        // (row * rowSize + column).
        std::unordered_set<int>& used
    ){

        int OneDCoordinate = currentY * board[0].size() + currentX;

        // First we check that the coordinate we are at exists.
        if(currentY < 0 || currentY >= board.size()
        || currentX < 0 || currentX >= board[0].size()){
            return false;
        }
        // Then we ensure the entry matches the word letter at this index
        else if (word[currentIndex] != board[currentY][currentX]) {
            return false;
        }
        // We then check the letter hasn't been chosen before
        else if (used.find(OneDCoordinate) != used.end()){
            return false;
        }
        // If it fits all criteria, and it is the last letter of the word,
        // we return true.
        else if (currentIndex == word.size() - 1){
            return true;
        }
        // Else, we just check all 4 directions we can go to, and return
        // true if any of them is true. We also add this entry to the list
        // of used entries.
        else{

            used.insert(OneDCoordinate);

            bool returnValue = (
                recursive(currentY, currentX - 1, currentIndex + 1, board, word, used)
                || recursive(currentY, currentX + 1, currentIndex + 1, board, word, used)
                || recursive(currentY - 1, currentX, currentIndex + 1, board, word, used)
                || recursive(currentY + 1, currentX, currentIndex + 1, board, word, used)
            );
            
            // We then erase the used coordinate when we backtrack,
            // since at the previous index we were at, we hadn't yet used
            // this entry. This can be avoided by sending the used set by value,
            // not reference, but it would be too slow.
            used.erase(OneDCoordinate);

            return returnValue;
        }
    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                std::unordered_set<int> used;
                if(recursive(i, j, 0, board, word, used)){
                    return true;
                }
            }
        }
        return false;
    }
    */

};