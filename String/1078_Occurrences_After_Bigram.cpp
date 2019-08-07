/******************************************************************************************
1078. Occurrences After Bigram
Easy

Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
******************************************************************************************/


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        string pattern = first + " " + second + " ";
        size_t N = pattern.size();
        
        vector<string> result;
        size_t pos = 0;
        do {
            size_t idx = text.find(pattern, pos);
            
            if(idx != string::npos) {
                size_t space = text.find_first_of(' ', idx+N);
                if(space != string::npos) result.push_back(text.substr(idx+N, space-idx-N));
                else 
                    result.push_back(text.substr(idx+N));
                pos = idx+N;
            } else {
                pos = string::npos;
            }
        } while(pos != string::npos);
        return result;
    }
};