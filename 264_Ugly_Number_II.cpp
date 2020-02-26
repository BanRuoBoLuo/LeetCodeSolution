/*******************************************************************************************
264. Ugly Number II
Medium

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

    1 is typically treated as an ugly number.
    n does not exceed 1690.


*******************************************************************************************/

class Solution {
private:
    // set is a ordered container
    std::set<long long> candidates;
        
    void addCandidates(long long x) {
        if(candidates.find(x) == candidates.end()) {
            candidates.insert(x);
        }
    }
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        
        addCandidates(2); addCandidates(3);  addCandidates(5); 
        
        long long result = 0;
        for(int i=1; i<n; i++) {
            result = *candidates.begin();
            candidates.erase(candidates.begin());
         
            if(result%2 == 0) {
                addCandidates(result*2); addCandidates(result*3); addCandidates(result*5);
            }
            else if (result%3 == 0){
                addCandidates(result*3); addCandidates(result*5);
            } else { 
                addCandidates(result*5);
            }
        }
        
        return result;
    }
};
    


class Solution {
private:
    std::unordered_set<long long> candidates;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;
        
    void addCandidates(long long x) {
        if(candidates.find(x) == candidates.end()) {
            q.push(x); 
            candidates.insert(x);
        }
    }
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        
        q.push(2); q.push(3); q.push(5);
        candidates.insert(2); candidates.insert(3);  candidates.insert(5); 
        
        long long result = 0;
        for(int i=1; i<n; i++) {
            result = q.top(); q.pop();
            candidates.erase(result);
         
            if(result%2 == 0) {
                addCandidates(result*2); addCandidates(result*3); addCandidates(result*5);
            }
            else if (result%3 == 0){
                addCandidates(result*3); addCandidates(result*5);
            } else { 
                addCandidates(result*5);
            }
        }
        
        return result;
    }
};
    