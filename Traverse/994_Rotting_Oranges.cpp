/*******************************************************************************************
994. Rotting Oranges
Easy

In a given grid, each cell can have one of three values:

    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:

Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.

 

Note:

    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] is only 0, 1, or 2.

*******************************************************************************************/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        
        int M = grid.size(), N = grid[0].size();
        int fresh = 0;
        
        queue<pair<int, int>> rt;
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                if(grid[i][j] == 2) {
                    rt.push(make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    fresh ++;
                }
            }
        }
        
        int minute = 0;
        while(!rt.empty()) {
            
            int sz = rt.size();
            for(int k=0; k<sz; k++) {
                pair<int, int> p = rt.front(); rt.pop();
                int i=p.first, j = p.second;
                if(isValid(i+1, j, M, N) && grid[i+1][j] == 1) {
                    grid[i+1][j] = 2; fresh --;
                    rt.push(make_pair(i+1, j));
                } 
                if(isValid(i-1, j, M, N) && grid[i-1][j] == 1) {
                    grid[i-1][j] = 2; fresh --;
                    rt.push(make_pair(i-1, j));
                }
                if(isValid(i, j+1, M, N) && grid[i][j+1] == 1) {
                    grid[i][j+1] = 2; fresh --;
                    rt.push(make_pair(i, j+1));
                }
                if(isValid(i, j-1, M, N) && grid[i][j-1] == 1) {
                    grid[i][j-1] = 2; fresh --;
                    rt.push(make_pair(i, j-1));
                }
            }
            if(!rt.empty())minute ++;
        }
        
        if(fresh > 0) return -1;
        return minute;
    }
    
    bool isValid(int i, int j, int M, int N) {
        return i>=0 && i<M && j >= 0 && j <N;
    }
};