/*************************************************************************
125. Valid Palindrome
Easy

Given a string, determine if it is a palindrome, considering only alphanumeric
 characters and ignoring cases.
For example,
”A man, a plan, a canal: Panama” is a palindrome.
”race a car” is not a palindrome.

Note: Have you consider that the string might be empty? 
This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*************************************************************************/

class Solution {
public:
  bool isPalindrome(string s) {

  	int left = 0, right = s.size()-1;
  	while(left < right) {
  		if(!isalnum(s[left])) left ++;
  		else if(!isalnum(s[right])) right --;
  		else if(tolower(s[left]) != tolower(s[right])) return false;
		else {
  			left ++; right --;
		}
  	}
  	return true;
  }
};