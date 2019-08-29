/******************************************************************************************
500. Keyboard Row
Easy

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]


******************************************************************************************/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        static regex re("^[qwertyuiopQWERTYUIOP]*|[asdfghjklASDFGHJKL]*|[zxcvbnmZXCVBNM]*$");
        vector<string> ret;
        for (auto& word : words) {
            if (regex_match(word, re)) ret.push_back(word);
        }
        return ret;
    }
};