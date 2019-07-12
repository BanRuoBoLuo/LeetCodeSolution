/*******************************************************************************************
200. Number of Islands
Medium

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
*******************************************************************************************/

#include <vector>
using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        int M = grid.size(), N = grid[0].size();
        
        int cnt = 0;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(grid[i][j] == '1') {
                    cnt ++;
                    traverse(grid, i, j);
                }
            }
        }
        
        return cnt;
    }
    
    void traverse(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(grid[i][j] != '1') return;
        
        grid[i][j] = '*';
        traverse(grid, i+1, j);
        traverse(grid, i-1, j);
        traverse(grid, i, j+1);
        traverse(grid, i, j-1);
    }
};