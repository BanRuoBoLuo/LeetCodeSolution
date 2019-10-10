/*******************************************************************************************
859. Buddy Strings
Easy

Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 

Example 1:

Input: A = "ab", B = "ba"
Output: true

Example 2:

Input: A = "ab", B = "ab"
Output: false

Example 3:

Input: A = "aa", B = "aa"
Output: true

Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true

Example 5:

Input: A = "", B = "aa"
Output: false

 

Note:

    0 <= A.length <= 20000
    0 <= B.length <= 20000
    A and B consist only of lowercase letters
*******************************************************************************************/


    class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        
        int cnt=0;
        vector<int> chars(26, 0);
        bool containsDuplicates = A.size() > 26;
        vector<int> pos;
        for(int i=0; i<A.size(); i++) {
            if(++chars[A[i]-'a'] > 1) containsDuplicates = true;
            
            if(A[i] != B[i]){
                if(++cnt > 2) return false;
                pos.push_back(i);
            }
        }
        
        if(cnt == 2) return A[pos[0]] == B[pos[1]] && A[pos[1]] == B[pos[0]];
        if(cnt == 0) return containsDuplicates;
        return false;
    }
};