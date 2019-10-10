/******************************************************************************************
1180. Count Substrings with Only One Distinct Letter
Easy

Given a string S, return the number of substrings that have only one distinct letter.

 

Example 1:

Input: S = "aaaba"
Output: 8
Explanation: The substrings with one distinct letter are "aaa", "aa", "a", "b".
"aaa" occurs 1 time.
"aa" occurs 2 times.
"a" occurs 4 times.
"b" occurs 1 time.
So the answer is 1 + 2 + 4 + 1 = 8.

Example 2:

Input: S = "aaaaaaaaaa"
Output: 55

 

Constraints:

    1 <= S.length <= 1000
    S[i] consists of only lowercase English letters.

******************************************************************************************/

class Solution {
public:
    int countLetters(string S) {
        size_t pivot=0, idx = 0;
        int cnt = 0;
        
        for(; idx < S.size(); idx++) {
            if(S[idx] != S[pivot]){
                cnt += (idx-pivot)*(idx-pivot+1)/2;
                pivot = idx;
            }
        }
        cnt += (idx-pivot)*(idx-pivot+1)/2;
        return cnt;
    }
};