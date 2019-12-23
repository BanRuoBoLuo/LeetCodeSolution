/*******************************************************************************************
166. Fraction to Recurring Decimal
Medium

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:

Input: numerator = 2, denominator = 1
Output: "2"

Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"


*******************************************************************************************/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        bool positive = true;
        if (numerator < 0) {
            positive = !positive;
            numerator = -numerator;
        }
        
        if (denominator < 0) {
            positive = !positive;
            denominator = -denominator;
        }
        
        int itg = numerator/denominator;
        numerator = numerator%denominator;
        if(numerator==0) {
            return positive? to_string(itg): "-" + to_string(itg);
        }
        
        string fraction;
        unordered_map<int, int> digit;
        int idx = 0;
        while(numerator > 0 && digit.find(numerator) == digit.end()) {
            digit[numerator] = idx++;
            
            fraction.push_back('0'+numerator*10/denominator);
            numerator = numerator*10%denominator;
        }
        
        if(numerator != 0) {
            fraction = fraction.substr(0, digit[numerator]) + "(" + fraction.substr(digit[numerator]) + ")";
        }
        fraction = to_string(itg) + "." + fraction;
        return positive? fraction: "-" + fraction;
    }
};