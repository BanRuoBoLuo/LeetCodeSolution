/*******************************************************************************************
93. Restore IP Addresses
Medium

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]


*******************************************************************************************/


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string path;
        vector<string> result;
        
        traverse(s, 0, 0, path, result);
        return result;
    }
    
    void traverse(string s, int pos, int step, string path, vector<string>& result) {
        if(s.size() < pos + 4-step || s.size() > pos + (4-step)*3) return;
        
        if(pos == s.size() && step == 4) {
            string r = path.substr(0, path.size()-1);
            result.push_back(r);
            return;
        }
        
        if(s[pos] == '0') {
            path += "0.";
            traverse(s, pos+1, step+1, path, result);
            path.pop_back();
            path.pop_back();
            return;
        }
        
        for(int len=1; len<=3; len++) {
            string p = s.substr(pos, len);
            if(stoi(p) <= 255) {
                path += p +".";
                traverse(s, pos+len, step+1, path, result);
                path = path.substr(0, path.size()-p.size()-1);
            }
        }
    }
};