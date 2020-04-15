/*************************************************************************
1314. Matrix Block Sum
Medium
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.

 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]

Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n, K <= 100
    1 <= mat[i][j] <= 100


*************************************************************************/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        if(mat.empty()) return mat;
        
        int M = mat.size(), N = mat[0].size();
        
        vector<vector<int>> dp(M, vector<int> (N, 0));
        dp[0][0] = mat[0][0];
        for(int i=1; i<M; i++) {
            dp[i][0] = dp[i-1][0] + mat[i][0];
        }
        for(int j=1; j<N; j++) {
            dp[0][j] = dp[0][j-1] + mat[0][j];
        }
        for(int i=1; i<M; i++) {
            for(int j=1; j<N; j++) {
                dp[i][j] = mat[i][j]+dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        vector<vector<int>> result(M, vector<int> (N, 0));
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                int mnI = max(0, i-K), mnJ = max(0, j-K);
                int mxI = min(M-1, i+K), mxJ=min(N-1, j+K);
                
                result[i][j] = dp[mxI][mxJ];
                if(mnI > 0) {
                    result[i][j] -= dp[mnI-1][mxJ];
                }
                if(mnJ > 0) {
                    result[i][j] -= dp[mxI][mnJ-1];
                }
                if(mnI > 0 && mnJ > 0) {
                    result[i][j] += dp[mnI-1][mnJ-1];
                }
            }
        }
        return result;
    }
    
    void printMat(const vector<vector<int>>& mat) {
        if(mat.empty()) return;
        
        int M = mat.size(), N = mat[0].size();
        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                cout << mat[i][j] << "   ";
            }
            cout << endl;
        }
    }
};