/*******************************************************************************************
985. Sum of Even Numbers After Queries
Easy

We have an array A of integers, and an array queries of queries.
For the i-th query val = queries[i][0], index = queries[i][1], we add val to A[index].  Then, the answer to the i-th query is the sum of the even values of A.
(Here, the given index = queries[i][1] is a 0-based index, and each query permanently modifies the array A.)
Return the answer to all queries.  Your answer array should have answer[i] as the answer to the i-th query.
*******************************************************************************************/
 
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        
        int evenSum = 0;
        for(int x : A) {
            if(x%2 == 0) evenSum += x;
        }
        
        vector<int> result;
        for (vector<int> q : queries) {
            if (A[q[1]]%2 == 0 && q[0] % 2 == 0) {
                evenSum += q[0];
            }
            else if (A[q[1]]%2 != 0 && q[0] % 2 != 0) {
                evenSum += q[0] + A[q[1]];
            }
            else if (A[q[1]]%2 == 0 && q[0] % 2 != 0) {
                evenSum -= A[q[1]];
            }
            
            result.push_back(evenSum);
            A[q[1]] += q[0];
        }
        
        return result;
    }
};