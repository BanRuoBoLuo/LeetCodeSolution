/*******************************************************************************************
1089. Duplicate Zeros
Easy

Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]

 

Note:

    1 <= arr.length <= 10000
    0 <= arr[i] <= 9

*******************************************************************************************/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int N = arr.size();
        
        int idx = -1, len = 0;
        while(len < N ){
            if(arr[++idx] != 0) len++;
            else len += 2;
        }
        
        if(len == N +1) {
            arr[N-1] = 0;
            len -= 2;
            idx --;
        }
        
        while(len>0) { 
            arr[--len] = arr[idx];
            if(arr[idx] == 0) arr[--len] = 0;
            --idx;
        }
    }
};