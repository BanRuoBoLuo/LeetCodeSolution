/*******************************************************************************************

1043. Partition Array for Maximum Sum
Medium

Given an integer array A, you partition the array into (contiguous) subarrays of length at most K.  After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.

 

Example 1:

Input: A = [1,15,7,9,2,5,10], K = 3
Output: 84
Explanation: A becomes [15,15,15,9,10,10,10]

 

Note:

    1 <= K <= A.length <= 500
    0 <= A[i] <= 10^6

*******************************************************************************************/


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        
        int N = A.size();
        vector<int> result(N, 0);
        
        int maxnum = 0;
        for(int i=0; i<K && i < N; i++) {
            maxnum = max(A[i], maxnum);
            result[i] = (i+1) * maxnum;
        }
        
        for(int i=K; i<N; i++) {
            maxnum = 0;
            for(int j=i-1; j>=i-K; j--){
                // maxnum = *max_element(A.begin()+j+1, A.begin()+i+1);
                maxnum = max(maxnum, A[j+1]);
                result[i] = max(result[i], maxnum*(i-j)+result[j]);
            }
        }
        return result[N-1];
    }
};