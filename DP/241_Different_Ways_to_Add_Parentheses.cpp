/*************************************************************************
241. Different Ways to Add Parentheses
Medium

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10


*************************************************************************/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        vector<int> nums;
        vector<char> ops;
        
        int pos = 0;
        for(int i=0; i<input.size(); i++) {
            if(!isdigit(input[i])) {
                nums.push_back(stoi(input.substr(pos, i-pos)));
                ops.push_back(input[i]);
                
                pos = i+1;
            }
        }
        nums.push_back(stoi(input.substr(pos)));
        
        int N = nums.size();
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (N));
        for(int i=0; i<N; i++) {
            dp[i][i].push_back(nums[i]);
        }
        
        
        for(int i=N-2; i >=0; i--){
            for(int j=i+1; j<N; j++) {
            
                for(int k=i; k<j; k++) {
                for(int a: dp[i][k]) {
                    for(int b: dp[k+1][j]) {
                        dp[i][j].push_back(cal(a, b, ops[k]));
                    }
                }
                }
            }
        }
        return dp[0][N-1];
    }
    
    int cal(int a, int b, char op) {
        switch(op) {
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            default:  return 0;
        }
    }
};