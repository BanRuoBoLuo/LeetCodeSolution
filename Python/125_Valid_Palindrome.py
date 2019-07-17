"""
125. Valid Palindrome
Easy

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true

Example 2:

Input: "race a car"
Output: false

"""

class Solution:
    def isPalindrome(self, s: str) -> bool:
        if not s:
            return True
        
        string = ''.join(c.lower() for c in s if c.isalnum())
        return string == string[::-1]

    def isPalindrome2(self, s: str) -> bool:

        s = s.lower()
        s = ''.join(list(filter(lambda x: x.isalnum(), s)))
        return s == s[::-1]