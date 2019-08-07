/*************************************************************************
908. Smallest Range I
Easy

Given an array A of integers, for each integer A[i] we may choose any x with -K <= x <= K, and add x to A[i].

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.

 

Example 1:

Input: A = [1], K = 0
Output: 0
Explanation: B = [1]

Example 2:

Input: A = [0,10], K = 2
Output: 6
Explanation: B = [2,8]

Example 3:

Input: A = [1,3,6], K = 3
Output: 0
Explanation: B = [3,3,3] or B = [4,4,4]


*************************************************************************/


class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min_num = INT_MAX, max_num = INT_MIN;
        for(int x: A) {
            min_num = min(min_num, x);
            max_num = max(max_num, x);
        }
        if(max_num  - min_num < 2 * K) return 0;
        else return max_num  - min_num -2*K;
    }
    
    int smallestRangeI2(vector<int>& A, int K) {
        auto max_it = max_element(A.begin(), A.end());
        auto min_it = min_element(A.begin(), A.end());
        
        if(*max_it - (*min_it) < 2 * K) return 0;
        else return (*max_it) - (*min_it) -2*K;
    }
};