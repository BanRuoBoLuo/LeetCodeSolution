/*******************************************************************************************
4. Median of Two Sorted Arrays
Hard

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


*******************************************************************************************/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        int N = nums2.size();
        
        int x = M+N;
        if( x % 2  == 0) {
            return 0.5* (findKthNumber(nums1.begin(), M, nums2.begin(), N, x/2) + findKthNumber(nums1.begin(), M, nums2.begin(), N, x/2 + 1) );
        } else {
            return findKthNumber(nums1.begin(), M, nums2.begin(), N, x/2 + 1);
        }
    }
    
    int findKthNumber(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k) {
        if(m > n) return findKthNumber(B, n, A, m, k);
        
        if(m == 0) return *(B+k-1);
        if(k == 1) return min(*A, *B);
        
        // M <= N
        int a = min(k/2, m), b = k-a;
        if(*(A+a-1) < *(B+b-1)) {
            return findKthNumber(A+a, m-a, B, n, k-a);
        } else if (*(A+a-1) > *(B+b-1)) {
            return findKthNumber(A, m, B+b, n-b, k-b);
        } else {
            return *(A+a-1);
        }
    }
        
    
        
};