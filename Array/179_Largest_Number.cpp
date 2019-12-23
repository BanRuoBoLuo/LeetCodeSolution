/******************************************************************************************
179. Largest Number
Medium

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"

Example 2:

Input: [3,30,34,5,9]
Output: "9534330"

Note: The result may be very large, so you need to return a string instead of an integer.

******************************************************************************************/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> strs(nums.size());
        transform(nums.begin(), nums.end(), strs.begin(), [](int x){
            return to_string(x);
        });
        
        sort(strs.begin(), strs.end(), [](string a, string b) {
            return a+b > b+a;
        });
        
        string rst;
        for(string& str: strs) rst += str;
        
        while(rst.size() > 1 && rst[0] == '0') rst.erase(rst.begin());
        return rst;
    }
    
    
};