/*******************************************************************************************
980. Unique Paths III
Hard

On a 2-dimensional grid, there are 4 types of squares:

    1 represents the starting square.  There is exactly one starting square.
    2 represents the ending square.  There is exactly one ending square.
    0 represents empty squares we can walk over.
    -1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)

Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

 

Note:

    1 <= grid.length * grid[0].length <= 20


*******************************************************************************************/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int M = grid.size(), N = grid[0].size();
        int steps = 0;
        int r = 0, c = 0;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == 0) steps ++;
                else if(grid[i][j] == 1) {
                    r = i; c = j;
                    grid[i][j] = 0;
                }
            }        
        }
        
        int cnt = 0;
        dfs(grid, M, N, r, c, steps+1, cnt);
        
        return cnt;
    }
    
    void dfs(vector<vector<int>>& grid, int M, int N, int r, int c, int step, int& count) {
        
        if(r < 0 || r >= M || c < 0 || c >= N) return;
        
        if(grid[r][c] == 2 && step == 0) {
            count ++;
            return;
        } 
        if (grid[r][c] != 0 ) {
            return;
        }
        
        grid[r][c] = -1;
        
        dfs(grid, M, N, r+1, c, step-1, count);
        dfs(grid, M, N, r-1, c, step-1, count);
        dfs(grid, M, N, r, c+1, step-1, count);
        dfs(grid, M, N, r, c-1, step-1, count);
        
        grid[r][c] = 0;
    }
};