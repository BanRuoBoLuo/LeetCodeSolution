/******************************************************************************************
1079. Letter Tile Possibilities
Medium

You have a set of tiles, where each tile has one letter tiles[i] printed on it.  Return the number of possible non-empty sequences of letters you can make.

 

Example 1:

Input: "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Example 2:

Input: "AAABBC"
Output: 188

 

Note:

    1 <= tiles.length <= 7
    tiles consists of uppercase English letters.


******************************************************************************************/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> nums(26, 0);
        for(char c: tiles) {
            nums[c-'A'] ++;
        }
        
        int total = 0;
        traverse(total, nums);
        return total;
    }
    
    void traverse(int& total, vector<int>& nums) {
        
        for(int& x: nums){
            if(x > 0){
                total ++; x --;
                traverse(total, nums);
                x ++;
            }
        }
    }
 };