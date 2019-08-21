/*******************************************************************************************
1119. Remove Vowels from a String
Easy

Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

 

Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Example 2:

Input: "aeiou"
Output: ""
*******************************************************************************************/


class Solution {
public:
    string removeVowels(string S) {
        int pos = 0;
        for (int i=0; i<S.size(); i++){
            if(vowels.find(S[i]) == string::npos) {
                S[pos] = S[i];
                pos ++;
            }
        }
        return S.substr(0, pos);
    }
    
    string vowels = "aeiouAEIOU";
};