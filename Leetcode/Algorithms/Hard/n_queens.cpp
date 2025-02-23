/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/n-queens/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    
        // Helper function that takes in a board as an argument
        // and returns true if none of the queens are attacking
        // each other.
        bool validBoard(vector<string> board){
    
            int n = board.size();
    
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
    
                    // For each queen
                    if (board[row][col] == 'Q') {
    
                        // No other queen is in the same column
                        // (We only need to check rows above since
                        // the rest queens below will later check
                        // this queen, which is redundant)
                        for (int i = 0; i < row; i++) {
                            if (board[i][col] == 'Q') return false;
                        }
                        
                        // Diagonal
                        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                            if (board[i][j] == 'Q') return false;
                        }
                        
                        // Other diagonal
                        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                            if (board[i][j] == 'Q') return false;
                        }
                    }
                }
            }
    
            return true;
        }
    
        // We can solve this using backtracking
        // This function is initially set to 0, 0, 0, empty board,
        // empty vector.
        // The first argument it takes is the current queen
        // that is placed (number of queen). We place queens row by row,
        // since there is exacytly most one queen at each row.
        // The second is the board up to this point,
        // sent as an n by n vector of dots and Qs.
        // The third is a vector of all valid positions found
        // thus far.
        void backtrack(
            int row, vector<string>& board, 
            vector<vector<string>>& boards
        ){
            // If the new queen made it invalid, backtrack
            if(!validBoard(board)){
                return;
            }
            
            // Else if we have reached the nth queen, we can
            // save this as a valid solution.
            if(row == board.size()){
                boards.push_back(board);
                return;
            }
    
            // Else, if it is valid, we need to fill the next
            // row with a queen, which can have one of n places.
            for(int i = 0; i < board[row].size(); i++){
                // We place a queen
                board[row][i] = 'Q';
                // We then do a DFS with the newly added queen
                backtrack(row + 1, board, boards);
                // We remove the queen from the board
                // so we can try other options (we use the same
                // board vector since it's faster to edit and send
                // by reference than to copy).
                board[row][i] = '.';
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            // We create a new n by n board all empty
            vector<string> board(n, string(n, '.'));
            vector<vector<string>> boards;
            backtrack(0, board, boards);
            return boards;
        }
    };