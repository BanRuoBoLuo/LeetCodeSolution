/******************************************************************************************
1010. Pairs of Songs With Total Durations Divisible by 60
Easy

In a list of songs, the i-th song has a duration of time[i] seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60

Example 2:

Input: [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.

 

Note:

    1 <= time.length <= 60000
    1 <= time[i] <= 500


******************************************************************************************/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rst(60, 0);
        for (int x: time) {
            rst[x%60] ++;
        }
        
        int result = rst[0]*(rst[0]-1)/2 + rst[30]*(rst[30]-1)/2 ;
        for(int i=1; i<30; i++) result += rst[i]*rst[60-i];

        return result;
    }
    
    int numPairsDivisibleBy60_2(vector<int>& time) {
        for(int& x: time) x = x%60;
        
        unordered_map<int, int> song;
        int result=0;
        for(int x: time) {
            if (x == 0) {
                result += song[0];
            } else {
                result += song[60-x];
            } 
            song[x] ++;
        }
        return result;
    }
};