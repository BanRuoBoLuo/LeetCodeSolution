/*******************************************************************************************
605. Can Place Flowers
Easy

Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: True

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: False

Note:

    The input array won't violate no-adjacent-flowers rule.
    The input array size is in the range of [1, 20000].
    n is a non-negative integer which won't exceed the input array size.


*******************************************************************************************/


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.empty()) return n == 0;
        
        int cnt = 0, N = flowerbed.size();
        if(flowerbed[0] == 0 && (N == 1 || flowerbed[1] == 0)) {
            cnt ++;
            flowerbed[0] = 1;
        }
        
        for(int i=1; i<N-1; i++) {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                cnt ++;
            }
        }
        
        if(N > 1 && flowerbed[N-1] == 0 && flowerbed[N-2] == 0) {
            cnt ++;
            flowerbed[N-1] = 1;
        }
        
        return  cnt >= n;
    }
};