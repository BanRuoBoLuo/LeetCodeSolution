/*******************************************************************************************
639. Decode Ways II
Hard

A message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:

Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

Example 2:

Input: "1*"
Output: 9 + 9 = 18

Note:

    The length of the input string will fit in range [1, 105].
    The input string will only contain the character '*' and digits '0' - '9'.


*******************************************************************************************/



class Solution {
public:
    int M = 1000000007;
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        
        int N = s.size();
        vector<long long> dp(N+1, 0);
        
        dp[0] = 1;
        dp[1] = s[0] == '*'? 9: 1;
        
        for(int i=1; i<N; i++) {
            if (s[i] == '*') {
                dp[i+1] = dp[i] * 9 % M;
                
                if (s[i-1] == '*') {
                    dp[i+1] =  (dp[i+1] + dp[i-1] * 15) % M;
                } else if (s[i-1] == '1') {
                    dp[i+1] = (dp[i+1] + dp[i-1] * 9) % M; 
                } else if (s[i-1] == '2') {
                    dp[i+1] = (dp[i+1] + dp[i-1] * 6) % M; 
                } 
            } else {
                dp[i+1] = s[i] == '0'? 0: dp[i];
                if (s[i-1] == '*') {
                    dp[i+1] = (dp[i+1] + dp[i-1]*(s[i] <= '6'? 2: 1))%M;
                } else if (s[i-1] == '1' ) {
                    dp[i+1] = (dp[i+1] + dp[i-1]) % M;
                } else if (s[i-1] == '2' && s[i] <= '6' ) {
                    dp[i+1] =  (dp[i+1] + dp[i-1]) % M;
                }
            } 
        }
        return dp[N];
    }
};