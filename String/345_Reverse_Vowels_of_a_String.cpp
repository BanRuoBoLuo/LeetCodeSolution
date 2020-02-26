/*************************************************************************
345. Reverse Vowels of a String
Easy

Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"

Example 2:

Input: "leetcode"
Output: "leotcede"

*************************************************************************/


class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "aoeiuAOEIU";
        int left =0, right = s.size()-1;
        while(left < right) {
            if(vowel.find(s[left]) == string::npos) left ++;
            else if (vowel.find(s[right]) == string::npos) right --;
            else {
                swap(s[left], s[right]);
                left ++; right --;
            }
        }
        
        return s;
    }
};