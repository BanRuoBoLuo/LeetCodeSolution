/*******************************************************************************************

401. Binary Watch
Easy

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]

*******************************************************************************************/
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    
    int bitsOfNumber(unsigned int x) {
        int result = 0;
        while (x>0) {
            result ++;
            x = (x-1)&x;
        }

        return result;
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<vector<string> > hours(5, vector<string> ());
        for(int i=0; i<12; i++){
            cout << i << '\t' << bitsOfNumber(i) << endl;
            hours[bitsOfNumber(i)].push_back(to_string(i));
        }
        
        vector<vector<string> > minutes(7, vector<string> ());
        for(int i=0; i<60; i++){
            string minute = to_string(i);
            if(minute.size()==1) minute = "0"+minute;
            minutes[bitsOfNumber(i)].push_back(minute);
        }
        
        vector<string> result;
        for(int h=0; h<=num && h<5; h++){
            if(num-h < 7){
                for(string hr: hours[h]) {
                for(string m: minutes[num-h]) {
                    result.push_back(hr+":"+m);
            }
        }
        return result;
    }
};

// int main() {
//     vector<string> rst = readBinaryWatch(7);
//     for(string& str : rst) cout << str << endl;

//     return 0;
// }


