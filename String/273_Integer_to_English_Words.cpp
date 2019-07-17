/******************************************************************************************
273. Integer to English Words
Hard

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"

Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

******************************************************************************************/

class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        
        string result;
        int billion = num/1000000000;
        if(billion > 0) {
            result += smallNumberToWords(billion) + " Billion ";
        }
        
        num = num%1000000000;
        int million = num/1000000;
        if(million > 0){
            result += smallNumberToWords(million) + " Million ";
        }
        
        num = num%1000000;
        int thousand = num/1000;
        if(thousand > 0){
            result += smallNumberToWords(thousand) + " Thousand ";
        }
        
        num = num%1000;
        if(num > 0){
            result += smallNumberToWords(num);
        }
        
        if(result.back()== ' ') result.pop_back();
        return result;
    }
    
    string smallNumberToWords(int num) {
        if(num==0) return "";
        
        vector<string> ones{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        string result;
        
        int hundred = num/100;
        if(hundred > 0) {
            result += ones[hundred] + " Hundred ";
        }
        
        num = num%100;
        if(num > 0 && num < 20) result += ones[num];
        else {
            int ten = num/10, one = num%10;
            if (ten > 0) result += tens[ten] + " ";
            if (one > 0) result += ones[one];
        }
        
        if(result.back() == ' ') result.pop_back();
        return result;
    }
};