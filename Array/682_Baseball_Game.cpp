/*******************************************************************************************
682. Baseball Game
Easy

You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

    Integer (one round's score): Directly represents the number of points you get in this round.
    "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
    "D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
    "C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.

Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:

Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.

Example 2:

Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.

*******************************************************************************************/


class Solution {
public:
    
    int calPoints(vector<string>& ops) {
        stack<int> validScores;
        
        for(string str: ops){
            if (str == "C" && !validScores.empty()) validScores.pop();
            else if (str == "D" && !validScores.empty()) validScores.push(validScores.top()*2);
            else if (str == "+" && validScores.size() >= 2) {
                int tmp1 = validScores.top(); validScores.pop();
                int tmp2 = validScores.top();
                validScores.push(tmp1);
                validScores.push(tmp1+tmp2);
            } else {
                validScores.push(stoi(str));
            }
        }
        
        int result = 0;
        while(!validScores.empty()) {
            result += validScores.top();
            validScores.pop();
        }
        
        return result;
    }
};