/******************************************************************************************
520. Detect Capital
Easy

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way.

 

Example 1:

Input: "USA"
Output: True

 

Example 2:

Input: "FlaG"
Output: False

 

Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

******************************************************************************************/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() < 2) return true;
        
        unsigned int result =  wordCase(word.substr(1));
        if(result == 0) return false;
        return allLower == result || isupper(word[0]);
    }
    
    unsigned int wordCase(const string& word) {
        unsigned int result = 0xFFFFFFFF;
        for(char c: word) {
            result = result & (isupper(c) ? allUpper: allLower);
        }
        return result;
    }
    
    const unsigned int allUpper = 0b10;
    const unsigned int allLower = 0b01;
};