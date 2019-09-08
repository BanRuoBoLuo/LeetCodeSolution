/*******************************************************************************************
74. Search a 2D Matrix
Medium

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false

*******************************************************************************************/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.empty()) return false;
        int M = matrix.size(), N = matrix[0].size();
        int i=0, j=N-1;
        while(i>=0 && i<M && j>=0 && j<N){
            if(matrix[i][j] < target) i++;
            else if (matrix[i][j] > target) j--;
            else return true;
        }
        return false;
    }
};