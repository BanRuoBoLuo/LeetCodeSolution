/******************************************************************************************
690. Employee Importance
Easy

You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.

Example 1:

Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
Output: 11
Explanation:
Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.

 

Note:

    One employee has at most one direct leader and may have several subordinates.
    The maximum number of employees won't exceed 2000.

******************************************************************************************/


/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        Employee *em = getEmployeeById(employees, id);
        if(em == nullptr) return 0;
        
        int importane = 0;
        queue<Employee*> ems;
        ems.push(em);
        
        while(!ems.empty()) {
            em = ems.front(); ems.pop();
            importane += em->importance;
            
            for(int idx: em->subordinates) {
                Employee* emp = getEmployeeById(employees, idx);
                if(emp != nullptr) ems.push(emp); 
            }
        }
        return importane;
    }
    
    Employee* getEmployeeById(const vector<Employee*>& employees, int id) {
        auto it = find_if(employees.begin(), employees.end(), [id](Employee* a){
            return a->id == id;
        });
        if(it == employees.end()) return nullptr;
        
        return *it;
    }
};