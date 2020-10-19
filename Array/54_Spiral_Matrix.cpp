/*******************************************************************************************
54. Spiral Matrix
Medium

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*******************************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int> {};
        
        int M = matrix.size(), N = matrix[0].size();
        vector<int> rst(M*N, 0);
        
        int layer = 0, idx = 0;
        while(2*layer < N-1 && 2*layer < M-1) {

            for(int j=layer; j<N-1-layer; j++) rst[idx++] = matrix[layer][j];
            for(int i=layer; i<M-1-layer; i++) rst[idx++] = matrix[i][N-1-layer];
            for(int j=N-1-layer; j>layer; j--) rst[idx++] = matrix[M-1-layer][j];
            for(int i=M-1-layer; i>layer; i--) rst[idx++] = matrix[i][layer];
            
            layer ++ ;
        }
        
       if(M < N && M%2 == 1) {
           for(int j=layer; j<=N-1-layer; j++) rst[idx++] = matrix[layer][j];
       } else if (N < M && N%2 == 1) {
           for(int i=layer; i<=M-1-layer; i++) rst[idx++] = matrix[i][N-1-layer];
       } else if (M == N && M%2 == 1) {
           rst[idx] = matrix[layer][layer];
       }
        
        return rst;
    }
};