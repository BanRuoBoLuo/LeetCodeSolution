/*************************************************************************

Given two binary strings, return their sum (also a binary string).
For example,
 a = "11" b = "1"
Return ”100”

*************************************************************************/

class Solution {
public:
  string addBinary(string a, string b) {
    if(a.size() > b.size()) return addBinary(b ,a);

    a = a.insert(0, b.size()-a.size(), '0');
    string result(a.size(), '0');
    int carry = 0;
    for(int i=a.size()-1; i>=0; i--){
        int x = (a[i]-'0') + (b[i] - '0') + carry;

        carry = x/2;
        result[i] = '0'+(x%2);
    }

    if(carry > 0) return "1" + result;
    else return result;
  }
};