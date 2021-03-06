/******************************************************************************************
557. Reverse Words in a String III
Easy

Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Note: In the string, each word is separated by single space and there will not be any extra space in the string. 

******************************************************************************************/


class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string result;
        
        while(ss >> word){
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};