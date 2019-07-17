/*********************************************************************************************
1119. Remove Vowels from a String
Easy

Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.

 

Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"

Example 2:

Input: "aeiou"
Output: ""
*********************************************************************************************/


class Solution {
public:
    string removeVowels(string S) {
        
        int pivot = 0;
        for(int i=0; i<S.size(); i++) {
            if(S[i] != 'a' && S[i] != 'o' && S[i] != 'e' &&S [i] != 'i' && S[i] != 'u') {
                S[pivot++] = S[i];
            }
        }
        
        return S.substr(0, pivot);
    }
    
    string removeVowels2(string S) {
        auto it = remove_if(S.begin(), S.end(), [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        });
        
        S.erase(it, S.end());
        return S;
    }
};