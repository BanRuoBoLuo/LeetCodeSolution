/*******************************************************************************************
763. Partition Labels
Medium

A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.

Note:

    S will have length in range [1, 500].
    S will consist of lowercase letters ('a' to 'z') only.

*******************************************************************************************/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        
        int bgn = 0;
        while(bgn < S.size()) {
            size_t lst = bgn;
            for(int i=bgn; i<=lst; i++) {
                lst = max(lst, S.find_last_of(S[i]));
            }
            result.push_back(lst-bgn+1);
            bgn = lst+1;
        }
        return result;
    }
};