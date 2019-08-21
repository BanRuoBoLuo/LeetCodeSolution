/*******************************************************************************************
824. Goat Latin
Easy

A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

    If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
    For example, the word 'apple' becomes 'applema'.
     
    If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
    For example, the word "goat" becomes "oatgma".
     
    Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
    For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.

Return the final sentence representing the conversion from S to Goat Latin. 

********************************************************************************************/


class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        vector<string> words;
        string input;
        while(ss >> input) {
            words.push_back(input);
        }
        
        int idx = 1;
        for(string& word : words) conversion(word, idx++);
        
        string result;
        for(const string& word : words) {
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
    
    void conversion(string& word, int idx) {
        if(word.empty()) return;
        
        char c = word[0];
        if(vowel.find_first_of(c) == string::npos){
            word.erase(word.begin());
            word.push_back(c);
        }
        word.append("ma");
        word.append(idx, 'a');
    }
    
    const string vowel = "aeiouAEIOU";
    
};