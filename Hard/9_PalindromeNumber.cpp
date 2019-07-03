/******************************************************************************************
9. Palindrome Number
Easy

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the 
same backward as forward.
******************************************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        int d = 1;
        while (x / d >= 10) d *= 10;
        
        while(x > 0) {
            if(x/d != x%10) return false;
            x = x%d/10;
            d = d/100;
        }
        
        return true;
    }
};