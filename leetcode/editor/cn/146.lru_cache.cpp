//Design and implement a data structure for Least Recently Used (LRU) cache. It 
//should support the following operations: get and put. 
//
// get(key) - Get the value (will always be positive) of the key if the key exis
//ts in the cache, otherwise return -1. 
//put(key, value) - Set or insert the value if the key is not already present. W
//hen the cache reached its capacity, it should invalidate the least recently used
// item before inserting a new item. 
//
// The cache is initialized with a positive capacity. 
//
// Follow up: 
//Could you do both operations in O(1) time complexity? 
//
// Example: 
//
// 
//LRUCache cache = new LRUCache( 2 /* capacity */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // returns 1
//cache.put(3, 3);    // evicts key 2
//cache.get(2);       // returns -1 (not found)
//cache.put(4, 4);    // evicts key 1
//cache.get(1);       // returns -1 (not found)
//cache.get(3);       // returns 3
//cache.get(4);       // returns 4
// 
//
// 
// Related Topics 设计 
// 👍 734 👎 0


#include "assert.h"
#include <iostream>
#include "list"
#include "unordered_map"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LRUCache {
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            int res = (*mp[key]).second;
            li.erase(mp[key]);
            li.push_front(make_pair(key, res));
            mp[key] = li.begin();
            return res;
        }

        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            li.erase(mp[key]);
        } else {
            if (cap == li.size()) {
                mp.erase(li.back().first);
                li.pop_back();
            }
        }

        li.push_front(make_pair(key, value));
        mp[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    LRUCache* cache = new LRUCache( 2 /* capacity */ );

    cache->put(1, 1);
    cache->put(2, 2);
    assert(cache->get(1) == 1);
    cache->put(3, 3);    // evicts key 2
    assert(cache->get(2) == -1);
    cache->put(4, 4);    // evicts key 1
    assert(cache->get(1) == -1);
    assert(cache->get(3) == 3);
    assert(cache->get(4) == 4);

    return 0;
}