/********************************************************************************************
3. Longest Substring Without Repeating Characters
Medium

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

*********************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int maxLen = 0;
        
        int left = -1;
        unordered_map<char, int> pos;
        for(int i=0; i<s.size(); i++){
            if(pos.find(s[i]) != pos.end() && pos[s[i]] > left){
                left = pos[s[i]];
            }
            pos[s[i]] = i;
            maxLen = max(maxLen, i-left);
        }
        return maxLen;
    }
};