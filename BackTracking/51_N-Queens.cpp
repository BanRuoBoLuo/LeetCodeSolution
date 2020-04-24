/*******************************************************************************************
51. N-Queens
Hard

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.


*******************************************************************************************/



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        column = string(n, '.');
        dia1 = string(2*n, '.');
        dia2 = string(2*n, '.');
        
        vector<string> path;
        vector<vector<string>> result;
        
        traverse(n, 0, path, result);
        return result;
    }
    
 private:
    void traverse(int n, int row, vector<string>& path, vector<vector<string>> & result) {
        if(n == row) {
            result.push_back(path);
            return;
        }
        
        for(int col = 0; col < n; col ++) {
            if(valid(row, col, n)) {
                string loc(n, '.');
                loc[col] = 'Q';
                
                path.push_back(loc);
                column[col] = 'Q'; dia1[row+col] = 'Q'; dia2[n-row+col] = 'Q';
                
                traverse(n, row+1, path, result);
                path.pop_back();
                column[col] = '.'; dia1[row+col] = '.'; dia2[n-row+col] = '.';
            }
        }
    }
    
    bool valid(int i, int j, int n) {
        return column[j] == '.' && dia1[i+j] == '.' && dia2[n-i+j] == '.';
    }
    
    string column;
    string dia1, dia2;    
};