/*************************************************************************
204. Count Primes
Easy

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*************************************************************************/


class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> nums(n, true);
        
        nums[0] = false; nums[1] = false;
        for(int i=2; i*i<n; i++) {
            if (nums[i]) {
                for(int j=i*i; j<n; j=j+i) {
                    nums[j] = false;
                }
            }
        }
        return std::count(nums.begin(), nums.end(), true);
    }
};