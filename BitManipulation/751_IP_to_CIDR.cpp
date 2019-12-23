/*************************************************************************
751. IP to CIDR
Easy

Given a start IP address ip and a number of ips we need to cover n, return a representation of the range as a list (of smallest possible length) of CIDR blocks.

A CIDR block is a string consisting of an IP, followed by a slash, and then the prefix length. For example: "123.45.67.89/20". That prefix length "20" represents the number of common prefix bits in the specified range.

Example 1:

Input: ip = "255.0.0.7", n = 10
Output: ["255.0.0.7/32","255.0.0.8/29","255.0.0.16/32"]
Explanation:
The initial ip address, when converted to binary, looks like this (spaces added for clarity):
255.0.0.7 -> 11111111 00000000 00000000 00000111
The address "255.0.0.7/32" specifies all addresses with a common prefix of 32 bits to the given address,
ie. just this one address.

The address "255.0.0.8/29" specifies all addresses with a common prefix of 29 bits to the given address:
255.0.0.8 -> 11111111 00000000 00000000 00001000
Addresses with common prefix of 29 bits are:
11111111 00000000 00000000 00001000
11111111 00000000 00000000 00001001
11111111 00000000 00000000 00001010
11111111 00000000 00000000 00001011
11111111 00000000 00000000 00001100
11111111 00000000 00000000 00001101
11111111 00000000 00000000 00001110
11111111 00000000 00000000 00001111

The address "255.0.0.16/32" specifies all addresses with a common prefix of 32 bits to the given address,
ie. just 11111111 00000000 00000000 00010000.

In total, the answer specifies the range of 10 ips starting with the address 255.0.0.7 .

There were other representations, such as:
["255.0.0.7/32","255.0.0.8/30", "255.0.0.12/30", "255.0.0.16/32"],
but our answer was the shortest possible.

Also note that a representation beginning with say, "255.0.0.7/30" would be incorrect,
because it includes addresses like 255.0.0.4 = 11111111 00000000 00000000 00000100 
that are outside the specified range.

Note:

    ip will be a valid IPv4 address.
    Every implied address ip + x (for x < n) will be a valid IPv4 address.
    n will be an integer in the range [1, 1000].

*************************************************************************/

class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> rst;

        unsigned int N = ipToUInt(ip);
        
        do{
            int mask = N & (-N);
            while(mask > n) mask = mask >> 1;
        
            rst.push_back(UIntToIp(N) + "/"+to_string(32-numOfDigits(mask)+1));
            N = N + mask;
            n -= mask;
        } while(n > 0);
            
        return rst;
    }
    
    int numOfDigits(int x) {
        int cnt = 0;
        while(x>0) {
            cnt ++;
            x = x>> 1;
        }
        return cnt;
    }
    
    unsigned int ipToUInt(const string& ip) {
        unsigned int x = 0;
        
        stringstream ss(ip);
        string piece;
        while(std::getline(ss, piece, '.')){
            x = x*0x100 + stoi(piece);
        }
        return x;
    }
    
    string UIntToIp(unsigned int x) {
        int base = 0x1000000;
        string rst;
        for(int i=0; i<4; i++){
            int rmd = x & 0xff;
            rst = to_string(rmd) + "." + rst;
            x = x >> 8;
        }
        rst.pop_back();
        return rst;
    }
};