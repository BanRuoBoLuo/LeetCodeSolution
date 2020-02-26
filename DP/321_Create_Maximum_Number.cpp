/*************************************************************************
321. Create Maximum Number
Hard

Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.

Note: You should try to optimize your time and space complexity.

Example 1:

Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:
[9, 8, 6, 5, 3]

Example 2:

Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:
[6, 7, 6, 0, 4]

Example 3:

Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:
[9, 8, 9]


*************************************************************************/
class Solution {
public:
    vector<int> maxNumberDP(vector<int>& A, vector<int>& B, int k) {
        
        int M = A.size(), N = B.size();
        vector<vector<string>> dp(M+1, vector<string> (N+1));
        vector<vector<string>> tmp(M+1, vector<string> (N+1));
        
        for(int x=1; x<=k; x++) {
            for(int i=1; i<=M; i++)
                tmp[i][0] = max(dp[i-1][0]+to_string(A[i-1]), tmp[i-1][0]);
            
            for(int j=1; j<=N; j++) 
                tmp[0][j] = max(dp[0][j-1]+to_string(B[j-1]), tmp[0][j-1]);
            
            for(int i=1; i<=M; i++){
                for(int j=1; j<=N; j++){
                    tmp[i][j] = max( max(dp[i-1][j]+to_string(A[i-1]), dp[i][j-1]+to_string(B[j-1])),
                                     max(tmp[i-1][j], tmp[i][j-1]));
                }
            }
            
            dp = tmp;
        }
        
        string rst = dp[M][N];
        vector<int> result(rst.size(), 0);
        transform(rst.begin(), rst.end(), result.begin(), [](char c){return c-'0';});
        return result;
    }

    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        string path, rst;
        traverse(nums1, 0, nums2, 0, k, path, rst);
        
        vector<int> result(k);
        transform(rst.begin(), rst.end(), result.begin(), [](char c){return c-'0';});
        return result;
    }
    
    void traverse(const vector<int>& nums1, int p1, const vector<int>& nums2, int p2, int k, string& path, string& rst) {
        int M = nums1.size(), N = nums2.size();
        if(M-p1+N-p2 < k) return;
        if(k == 0) {
            rst = max(rst, path);
            return;
        }
        
        if(p1<M) {
            traverse(nums1, p1+1, nums2, p2, k, path, rst);
        }
        if(p2 < N) {
            traverse(nums1, p1, nums2, p2+1, k, path, rst);
        }
        if(p1<M) {
            path.push_back('0'+nums1[p1]);
            traverse(nums1, p1+1, nums2, p2, k-1, path, rst);
            path.pop_back();
        }
        
        if(p2 < N) {
            path.push_back('0'+nums2[p2]);
            traverse(nums1, p1, nums2, p2+1, k-1, path, rst);
            path.pop_back();
        }
    }
};