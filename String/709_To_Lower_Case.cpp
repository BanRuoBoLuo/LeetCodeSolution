/*************************************************************************
709. To Lower Case
Easy

Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

 

Example 1:

Input: "Hello"
Output: "hello"

Example 2:

Input: "here"
Output: "here"

Example 3:

Input: "LOVELY"
Output: "lovely"

*************************************************************************/


class Solution {
public:
    string toLowerCase(string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        // std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return tolower(c);});
        return str;
    }
};