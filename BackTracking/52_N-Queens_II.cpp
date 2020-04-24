/*******************************************************************************************
52. N-Queens II
Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


*******************************************************************************************/


class Solution {
public:
    int totalNQueens(int n) {
        column = string(n, '.');
        dia1 = string(n*2, '.');
        dia2 = string(n*2, '.');
        
        int count = 0;
        traverse(n, 0, count);
        
        return count;
    }
    
private: 
    void traverse(int n, int row, int& count) {
        if (row == n) {
            count ++;
            return;
        }
        
        for(int col = 0; col < n; col ++) {
            if(!isValid(row, col, n)) continue;
            
            column[col] = 'Q';
            dia1[row+col] = 'Q'; dia2[n-row+col] = 'Q';
                
            traverse(n, row+1, count);
                
            column[col] = '.';
            dia1[row+col] = '.'; dia2[n-row+col] = '.';
        }
        
    }
    
    bool isValid(int i, int j, int n) {
        return column[j] == '.' && dia1[i+j] == '.' && dia2[n-i+j] == '.';
    }

    string column;
    string dia1, dia2;
};