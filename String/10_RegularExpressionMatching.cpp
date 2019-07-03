/*****************************************************************************************
10. Regular Expression Matching
Hard

Given an input string (s) and a pattern (p), 
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.

*******************************************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        return matchExp(s.c_str(), p.c_str());
    }
    
    bool matchExp(const char* s, const char *p) {
        if(*p=='\0') return *s=='\0';
        
        //Match the first character
        bool firstMatch = *s==*p || (*s != '\0' && *p == '.');
        
        if(*(p+1)=='*') {
            return matchExp(s, p+2) || (firstMatch && matchExp(s+1, p));
        }
        else {
            return firstMatch && matchExp(++s, ++p);
        }
        
    }
};