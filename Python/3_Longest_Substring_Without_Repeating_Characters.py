"""
3. Longest Substring Without Repeating Characters
Medium

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

"""


class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        maxLen = 0
        left = -1
        pos = {}
        
        for i, c in enumerate(s):
            if c in pos:
                left = max(pos[c], left)
            pos[c] = i
            maxLen = max(i-left, maxLen)
            
        return maxLen