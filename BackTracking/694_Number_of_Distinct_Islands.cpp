/*************************************************************************
694. Number of Distinct Islands
Medium

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:

11000
11000
00011
00011

Given the above grid map, return 1.

Example 2:

11011
10000
00001
11011

Given the above grid map, return 3.

Notice that:

11
1

and

 1
11

are considered different island shapes, because we do not consider reflection / rotation.

Note: The length of each dimension in the given grid does not exceed 50. 

*************************************************************************/

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
               if(grid.empty()) return 0;
        
        int M = grid.size(), N = grid[0].size();

        unordered_set<string> shapes;
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(grid[i][j] == 1) {
                    string path("");
                    traverse(grid, i, j, i, j, path);
                    shapes.insert(path);
                }
            }
        }
        return shapes.size();
    }
    
    void traverse(vector<vector<int>>& grid, int i, int j, int row, int col, string& path) {
        int M = grid.size(), N = grid[0].size();
        if(i < 0 || i >= M || j < 0 || j >= N) return;
        if(grid[i][j] == 0)  return;
        
        grid[i][j] = 0;
        path += "("+ to_string(i-row)+", " + to_string(j-col)+")";
        traverse(grid, i-1, j, row, col, path);
        traverse(grid, i+1, j, row, col, path);
        traverse(grid, i, j-1, row, col, path);
        traverse(grid, i, j+1, row, col, path);
    }
};