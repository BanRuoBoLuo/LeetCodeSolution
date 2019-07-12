/*******************************************************************************************
989. Add to Array-Form of Integer
Easy

For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  
For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, 
return the array-form of the integer X+K.

Example 1:

Input: A = [1,2,0,0], K = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234

Example 2:

Input: A = [2,7,4], K = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
******************************************************************************************/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        
        int carry = K;
        for(int i=A.size()-1; carry > 0 && i>=0; i--) {
            A[i] = A[i] + carry;
            carry = A[i]/10;
            A[i] = A[i] % 10;
        }
        
        // vector<int> B;
        // while(carry > 0) {
        //     B.push_back(carry%10);
        //     carry /= 10;
        // }
        // A.insert(A.begin(), B.rbegin(), B.rend());
        
        if(carry > 0) {
            string num = to_string(carry);
            vector<int> B(num.size());
            transform(num.begin(), num.end(), B.begin(), [](char c){return (int)(c-'0');});
            A.insert(A.begin(), B.begin(), B.end());
        }
        return A;
    }
};