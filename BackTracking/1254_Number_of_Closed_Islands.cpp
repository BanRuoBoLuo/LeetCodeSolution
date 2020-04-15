/*************************************************************************
1254. Number of Closed Islands
Medium

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1

Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2

 

Constraints:

    1 <= grid.length, grid[0].length <= 100
    0 <= grid[i][j] <=1



*************************************************************************/


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int M = grid.size(), N = grid[0].size();
        for(int i=0; i<M; i++) {
            if(grid[i][0] == 0) traverse(grid, i, 0);
            if(grid[i][N-1] == 0) traverse(grid, i, N-1);
        }
        for(int j=1; j<N; j++) {
            if(grid[0][j] == 0) traverse(grid, 0, j);
            if(grid[M-1][j] == 0) traverse(grid, M-1, j);
        }
        
        int cnt = 0;
        for(int i=1; i<M; i++) {
            for(int j=1; j<N; j++) {
                if(grid[i][j] == 0) {
                    cnt ++;
                    traverse(grid, i, j);
                }
            }
        }
        return cnt;
    }
    
    void traverse(vector<vector<int>>& grid, int i, int j) {
        int M = grid.size(), N = grid[0].size();
        if(i < 0 || i >= M || j < 0 || j >= N) return;
        if(grid[i][j] == 1)  return;
        
        grid[i][j] = 1;
        traverse(grid, i-1, j);
        traverse(grid, i+1, j);
        traverse(grid, i, j-1);
        traverse(grid, i, j+1);
    }
};