/*******************************************************************************************
79. Word Search
Medium

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*******************************************************************************************/


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(traverse(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool traverse(vector<vector<char>>& board, int i, int j, const string& word, int pos) {
        if(pos == word.size()) return true;
        
        if(i<0 || i>=board.size() || j < 0 || j>= board[0].size() ) return false;
        if(board[i][j] != word[pos]) return false;
        
        char c = board[i][j];
        board[i][j] = '*';
        if(traverse(board, i+1, j, word, pos+1)) return true;
        if(traverse(board, i-1, j, word, pos+1)) return true;
        if(traverse(board, i, j+1, word, pos+1)) return true;
        if(traverse(board, i, j-1, word, pos+1)) return true;
        
        board[i][j] = c;
        return false;
        
            
    }
};