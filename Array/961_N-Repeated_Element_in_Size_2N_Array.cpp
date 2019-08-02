/*****************************************************************************************
961. N-Repeated Element in Size 2N Array
Easy

In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.

 

Example 1:

Input: [1,2,3,3]
Output: 3

Example 2:

Input: [2,1,2,5,3,2]
Output: 2

Example 3:

Input: [5,1,5,2,5,3,5,4]
Output: 5

 

Note:

    4 <= A.length <= 10000
    0 <= A[i] < 10000
    A.length is even

******************************************************************************************/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        assert(A.size() >= 4);
        
        if(A[0] == A[1]) return A[0];
        else if(A[0] == A[2] || A[1] == A[2]) return A[2];
        else {
            int cnt = 0, majority = -1;
            for(int i=3; i<A.size(); i++) {
                if(cnt == 0) {majority = A[i]; cnt = 1;}
                else if (majority == A[i]) cnt ++;
                else cnt --;
            }
            return majority;
        }
        
    }
};