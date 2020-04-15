/*******************************************************************************************
1081. Smallest Subsequence of Distinct Characters
Medium

Return the lexicographically smallest subsequence of text that contains all the distinct characters of text exactly once.

Example 1:

Input: "cdadabcc"
Output: "adbc"

Example 2:

Input: "abcd"
Output: "abcd"

Example 3:

Input: "ecbacba"
Output: "eacb"

Example 4:

Input: "leetcode"
Output: "letcod"

 

Constraints:

    1 <= text.length <= 1000
    text consists of lowercase English letters.


*******************************************************************************************/

class Solution {
public:
    string smallestSubsequence(string text) {
        unordered_map<char, int> cnt;
        for(char c: text) cnt[c] ++;
        
        string result;
        for(char c: text) {
            cnt[c] --;
            if(result.find(c) != string::npos) {
                continue;
            } else {
                while(!result.empty() && result.back() > c && 
                     cnt[result.back()] > 0) {
                    result.pop_back();
                }
                result.push_back(c);
            }
            
        }
        return result;
    }
};