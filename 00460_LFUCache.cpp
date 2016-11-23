/*
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.set(1, 1);
cache.set(2, 2);
cache.get(1);       // returns 1
cache.set(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.set(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
Subscribe to see which companies asked this question

Hide Tags Design
Hide Similar Problems (H) LRU Cache
Have you met this question in a real interview? Yes
*/

class LFUCache {
private:
    struct ListNode {
        list<pair<int, int>> kvs;
        int freq;
        ListNode(int k, int v, int f) : kvs({{k, v}}), freq(f) {}
    };

    unordered_map<int, pair<list<ListNode>::iterator, list<pair<int, int>>::iterator>> keymap;
    list<ListNode> matrix; 
    int cur_size, max_size;
public:
    LFUCache(int capacity) {
        cur_size = 0;   
        max_size = capacity;
    }
    
    int get(int key) {
        if (keymap.find(key) == keymap.end())
            return -1;
        auto row = keymap[key].first;
        auto col = keymap[key].second;
        int val = col->second;
        set(key, val);
        return val;
    }
    
    void set(int key, int value) {
        if (keymap.find(key) == keymap.end()) {
            if (max_size == 0)
                return;
            if (cur_size >= max_size)
                del();
            if (matrix.empty() || matrix.back().freq != 1) { //adding new key/val with freq(1) at the bottom
                auto newrow = matrix.emplace(matrix.end(), key, value, 1);
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            } else { //adding new key/val with freq(1) into the exsiting row
                auto newrow = --matrix.end();
                newrow->kvs.push_front({key, value});
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            }
            cur_size++;
        } else {
            auto row = keymap[key].first;
            auto col = keymap[key].second;
            auto lastrow = row;
            --lastrow;
            //if (lastrow == matrix.end() || lastrow->freq != row->freq + 1) {
            if (row == matrix.begin() || lastrow->freq != row->freq + 1) { //sorted by freqs from bigger to smaller
                auto newrow = matrix.emplace(row, key, value, row->freq + 1); //insert different freq with new kv list
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            } else { //update existing kv list
                auto newrow = lastrow;
                newrow->kvs.push_front({key, value});
                keymap[key] = make_pair(newrow, newrow->kvs.begin());
            }
            row->kvs.erase(col); //remove the key/val from old kvs list
            if (row->kvs.empty())
                matrix.erase(row);
        } 
    }

    void del() {
        if (cur_size <= 0)
            return;
        auto row = matrix.end(); //found key/val with least freq at the bottom
        row--;
        auto col = row->kvs.end();
        col--;
        int key = col->first;
        row->kvs.erase(col); //remove the kv from old kv list
        if (row->kvs.empty())
            matrix.erase(row);
        keymap.erase(key);
        cur_size--;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */
