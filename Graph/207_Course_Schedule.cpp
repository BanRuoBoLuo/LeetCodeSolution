/*************************************************************************
207. Course Schedule
Medium

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.


*************************************************************************/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> pres(numCourses, 0);
        map<int, vector<int>> pre_course;
        
        for(const vector<int>& p: prerequisites) {
            pres[p[0]] ++;
            pre_course[p[1]].push_back(p[0]);
        }
        
        queue<int> taken;
        for(int i=0; i<numCourses; i++) {
            if(pres[i] == 0) taken.push(i);
        }
        
        while(!taken.empty()) {
            int tk = taken.front(); taken.pop();

            for(int x: pre_course[tk]) {
                pres[x] --;
                if(pres[x] == 0) taken.push(x);
            }
        }
        
        for(int x: pres) {
            if(x > 0) return false;
        }
        return true;
      
    }
};