/******************************************************************************************
264. Ugly Number II
Medium

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

******************************************************************************************/

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> q;
        q.push(2);q.push(3);q.push(5);
        
        int result = 0;
        for(int i=1; i<n; i++) {
            result = q.top();
            
            while(!q.empty() && q.top() == result) q.pop();
            if(result < 0) continue;
            if(result%2 == 0) {q.push(result*2);q.push(result*3);q.push(result*5);}
            else if (result%3 == 0){q.push(result*3);q.push(result*5);}
            else { q.push(result*5);}
        }
        
        return result;
    }
    
    
//      std::priority_queue<int> q;
 
//     for(int n : {1,8,5,6,3,4,0,9,7,2})
//         q.push(n);
 
//     print_queue(q);
 
//     std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
 
//     for(int n : {1,8,5,6,3,4,0,9,7,2})
//         q2.push(n);
 
//     print_queue(q2);
 
//     // Using lambda to compare elements.
//     auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
//     std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
 
//     for(int n : {1,8,5,6,3,4,0,9,7,2})
//         q3.push(n);
 
//     print_queue(q3);
};