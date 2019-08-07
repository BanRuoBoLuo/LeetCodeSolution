/*******************************************************************************************
929. Unique Email Addresses
Easy

Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

 

Example 1:

Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails

*******************************************************************************************/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> email;
        
        for(const string& str: emails){
            string m = normalize(str);
            if(!m.empty()) email.insert(m);
        }
        return email.size();
    }
    
    string normalize(const string& email) {
        size_t at = email.find_first_of('@');
        if(at == string::npos) return "";
        
        string name = email.substr(0, at);
        size_t plus = name.find_first_of('+');
        if(plus != string::npos) name = name.substr(0, plus);
        
        auto it = std::remove(name.begin(), name.end(), '.');
        name.erase(it, name.end());

        return name + email.substr(at);
    }
};