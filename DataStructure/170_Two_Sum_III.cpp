/******************************************************************************************
170. Two Sum III - Data structure design
Easy

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false

Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false


******************************************************************************************/


class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        cnts[number] ++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto it = cnts.begin(); it != cnts.end(); ++it) {
            if(value == 2*it->first && it->second > 1) return true;
            else if(value != 2*it->first && cnts.find(value- it->first) != cnts.end()) return true;
        }
        return false;
    }
    
    private:
    unordered_map<int, int> cnts;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */