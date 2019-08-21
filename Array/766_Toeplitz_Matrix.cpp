/******************************************************************************************
766. Toeplitz Matrix
Easy

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.

Example 2:

Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

*****************************************************************************************/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) return true;
        
        int M = matrix.size(), N = matrix[0].size();
        for(int i=0; i<N; i++) {
            int pivot = matrix[0][i], idx = 1;
            while(idx<M && i+idx<N){
                if(matrix[idx][i+idx] != pivot) return false;
                idx++;
            }
        }
        
        for(int j=1; j<M; j++){
            int pivot = matrix[j][0], idx = 1;
            while(j+idx < M && idx < N){
                if(matrix[j+idx][idx] != pivot) return false;
                idx ++;
            }
        }
        
        return true;
    }

    bool isToeplitzMatrix2(vector<vector<int>>& matrix) {
        if(matrix.empty()) return true;
        
        int M = matrix.size(), N = matrix[0].size();
        for(int i=1; i<M ; i++) {
        	for(int j=1;j<N ;j++) {
        		if(matrix[i][j] != matrix[i-1][j-1])
        			return false;
        	}
        }
        return true;
        
    }
};