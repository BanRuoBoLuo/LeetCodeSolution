/*******************************************************************************************
1100. Find K-Length Substrings With No Repeated Characters
Medium

Given a string S, return the number of substrings of length K with no repeated characters.

 

Example 1:

Input: S = "havefunonleetcode", K = 5
Output: 6
Explanation: 
There are 6 substrings they are : 'havef','avefu','vefun','efuno','etcod','tcode'.

Example 2:

Input: S = "home", K = 5
Output: 0
Explanation: 
Notice K can be larger than the length of S. In this case is not possible to find any substring.

 

Note:

    1 <= S.length <= 10^4
    All characters of S are lowercase English letters.
    1 <= K <= 10^4

*******************************************************************************************/

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(K > S.size()) return 0;
        
        vector<int> letters(26, -1);
        int left = -1;
        int cnt = 0;
        for(int rgt = 0; rgt < S.size(); rgt++){
            int idx = S[rgt]-'a';
            if(letters[idx] != -1) left = max(letters[idx], left);
            if(rgt - left >= K) cnt ++;
            letters[idx] = rgt;
        }
        return cnt;
    }
};