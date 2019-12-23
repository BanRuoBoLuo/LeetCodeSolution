/*******************************************************************************************
1219. Path with Maximum Gold
Medium

In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

    Every time you are located in a cell you will collect all the gold in that cell.
    From your position you can walk one step to the left, right, up or down.
    You can't visit the same cell more than once.
    Never visit a cell with 0 gold.
    You can start and stop collecting gold from any position in the grid that has some gold.

 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.

 

Constraints:

    1 <= grid.length, grid[i].length <= 15
    0 <= grid[i][j] <= 100
    There are at most 25 cells containing gold.

*******************************************************************************************/

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int gold = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                gold = max(gold, traverse(grid, i, j) );
            }
        }
        return gold;
    }
    
    
    int traverse(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size())
            return 0;
        
        if(grid[row][col] == 0) return 0;
        
        int val = grid[row][col];
        
        grid[row][col] = 0;
        int u = traverse(grid, row-1, col);
        int d = traverse(grid, row+1, col);
        int l = traverse(grid, row, col-1);
        int r = traverse(grid, row, col+1);
        
        grid[row][col] = val;
        return max(max(u, d), max(l, r)) + val;
    }
};