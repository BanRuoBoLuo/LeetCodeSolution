/*******************************************************************************************
542. 01 Matrix
Medium

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]

 

Note:

    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.


*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return matrix;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> rst(m, vector<int> (n, 0));
        
        queue<pair<int, int>> loc;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) loc.push(make_pair(i, j));
            }
        }
        
        while(!loc.empty()) {
            pair<int, int> v = loc.front(); loc.pop();
            int i = v.first, j = v.second;
            if(visit(i+1, j, matrix, m, n, loc)) rst[i+1][j] = rst[i][j]+1;
            if(visit(i-1, j, matrix, m, n, loc)) rst[i-1][j] = rst[i][j]+1;
            if(visit(i, j+1, matrix, m, n, loc)) rst[i][j+1] = rst[i][j]+1;
            if(visit(i, j-1, matrix, m, n, loc)) rst[i][j-1] = rst[i][j]+1;
        }
        
        return rst;
    }
    
    bool visit(int i, int j, vector<vector<int>>& matrix, int m, int n, queue<pair<int, int>> & loc) {
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        if(matrix[i][j] == 0) return false;
        
        loc.push(make_pair(i, j));
        matrix[i][j] = 0;
        return true;
    }
};