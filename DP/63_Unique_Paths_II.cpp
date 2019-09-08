/*******************************************************************************************
63. Unique Paths II
Medium

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

*******************************************************************************************/



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()) return 0;
        
        int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        vector<long long> rst(N, 0);
        
        rst[0] = obstacleGrid[0][0] == 1? 0: 1;
        for(int j=1; j<N; j++) rst[j] = obstacleGrid[0][j] == 1? 0: rst[j-1];
        
        for(int i=1; i<M; i++){
            rst[0] = obstacleGrid[i][0] == 1? 0: rst[0];
            for(int j=1; j<N; j++){
                rst[j] = obstacleGrid[i][j] == 1? 0: rst[j-1] + rst[j];
            }
        }
        return rst[N-1];
    }
};