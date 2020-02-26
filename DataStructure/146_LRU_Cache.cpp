/******************************************************************************************
146. LRU Cache
Medium

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 ) // capacity of 2
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

 
******************************************************************************************/

class LRUCache {
private:
    struct CacheNode {
        int key, value;
        CacheNode(int k, int v): key(k), value(v) {}
    };
public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        auto it = keys.find(key);
        if(it == keys.end()) return -1;
        
        cache.splice(cache.begin(), cache, it->second);
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = keys.find(key);
        if(it == keys.end()) { // not in list, add in front
            if(cache.size() == capacity) {
                keys.erase(cache.back().key); 
                cache.pop_back();
            }
            
            cache.emplace_front(key, value);
            keys[key] = cache.begin();
        } else {
            cache.splice(cache.begin(), cache, it->second);
            it->second->value = value;
        }
    }
    
    typedef std::list<CacheNode>::iterator cit;
    std::unordered_map<int, cit> keys;
    std::list<CacheNode> cache;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */