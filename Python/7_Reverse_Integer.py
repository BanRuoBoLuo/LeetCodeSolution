"""
7. Reverse Integer
Easy

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

"""

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x, positive = abs(x), True if x>=0 else False
                
        y = 0
        while x > 0:
            y = y * 10 + x%10
            x = x //10
        
        y = y if positive else -y
        return y if y < 2**31-1 and y > -2**31 else 0
            

    def reverse2(self, x: int) -> int:
        if x < 0: 
            n = self.reverse(0-x) 
            return -n if n <= 2**31 else 0
        
        s = str(x)[::-1]
        n = int(s)
        return n if n < 2**31 else 0
        
    
        