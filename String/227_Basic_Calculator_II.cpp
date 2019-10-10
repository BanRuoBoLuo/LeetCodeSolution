/*******************************************************************************************
227. Basic Calculator II
Medium

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7

Example 2:

Input: " 3/2 "
Output: 1

Example 3:

Input: " 3+5 / 2 "
Output: 5

Note:

    You may assume that the given expression is always valid.
    Do not use the eval built-in library function.


*******************************************************************************************/

class Solution {
public:
    int calculate(string s) {
        vector<char> ops;
        vector<int> nums;
        
        size_t pos = 0;
        while(pos != string::npos) {
            size_t idx = s.find_first_of("+-*/", pos);
            int num = 0;
            if(idx == string::npos){
                num = stoi(s.substr(pos));
            } else {
                num = stoi(s.substr(pos, idx-pos));
            }
            
            if(!ops.empty()) {
                if (ops.back() == '*') {
                    num *= nums.back();
                    nums.pop_back();
                    ops.pop_back();
                } else if (ops.back() == '/') {
                    num = nums.back()/num;
                    nums.pop_back();
                    ops.pop_back();
                }
            } 
            nums.push_back(num);
            if (idx != string::npos){ 
                ops.push_back(s[idx]);
                pos = idx + 1;
            } else {
                break;
            }
        }
        
        int result = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(ops[i-1] == '+') result += nums[i];
            else if (ops[i-1] == '-') result -= nums[i];
        }
        return result;
    }


    int calculate2(string s) {
        char op = '+';
        vector<int> nums;
        
        size_t pos = 0;
        while(pos != string::npos) {
            size_t idx = s.find_first_of("+-*/", pos);
            int num = 0;
            if(idx == string::npos){
                num = stoi(s.substr(pos));
            } else {
                num = stoi(s.substr(pos, idx-pos));
            }
            
            if (op == '-') {
                num = 0-num;
            }else if (op == '*') {
                num *= nums.back();
                nums.pop_back();
            } else if (op == '/') {
                num = nums.back()/num;
                nums.pop_back();
            }
            
            nums.push_back(num);
            if (idx == string::npos) break;
            op = s[idx];
            pos = idx + 1;
        }
        
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};