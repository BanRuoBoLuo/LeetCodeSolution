/*******************************************************************************************
37. Sudoku Solver
Hard

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

    The given board contain only digits 1-9 and the character '.'.
    You may assume that the given Sudoku puzzle will have a single unique solution.
    The given board size is always 9x9.

*******************************************************************************************/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool solve = sudokuSolvable(board);
        return;
    }
    
    bool sudokuSolvable(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(int k=1; k<=9; k++) {
                        if(isValid(board, i, j, '0'+k)) {
                            board[i][j] = '0' + k;
                            if(sudokuSolvable(board)) return true;
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(const vector<vector<char>>& board, int x, int y, char c) {
        for(int i=0; i<9; i++) {
            if(i != x && board[i][y] == c) return false;
        }
        
        for(int j=0; j<9; j++) {
            if(j != y && board[x][j] == c) return false;
        }
        
        int xx = (x/3)*3, yy = (y/3)*3;
        for(int i=xx; i<xx+3; i++) {
            for(int j=yy; j<yy+3; j++) {
                if (i == x && j == y) continue;
                if ( board[i][j] == c) return false;
            }
        }
        return true;
    }
    
};