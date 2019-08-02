/*******************************************************************************************
1086. High Five
Easy

Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
*******************************************************************************************/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector< priority_queue<int, vector<int>, std::greater<int>>> scores(1001);
        
        for(const auto& item: items) {
            if(scores[item[0]].size() == 5 ) {
                if(scores[item[0]].top() < item[1]) {
                    scores[item[0]].pop();
                    scores[item[0]].push(item[1]);
                }
            } else {
                scores[item[0]].push(item[1]);
            }
        }
        
        vector<vector<int>> result;
        for(int id = 1; id<1001; id++) {
            int total = 0;
            int N = scores[id].size();
            while(!scores[id].empty()){total += scores[id].top(); scores[id].pop();}
            
            if(N > 0)  result.push_back(vector<int> {id, total/N});
        }
        
        return result;
    }
};