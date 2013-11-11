/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache{
public:
    LRUCache(int capacity) {
        max_size = capacity;
        cur_size = 0;
    }
    
    int get(int key) {
        if(entryMap.find(key)!=entryMap.end()){
            int value = entryMap[key]->second;
            entryList.erase(entryMap[key]);
            entryList.push_front(make_pair(key, value));
            entryMap[key] = entryList.begin();
            return value;
        }else
            return -1;
    }
    
    void set(int key, int value) {
        if(entryMap.find(key)==entryMap.end()){
            if(cur_size==max_size)
                del();
        }else{
            entryList.erase(entryMap[key]);
            cur_size--;
        }
        entryList.push_front(make_pair(key, value));
        entryMap[key] = entryList.begin();
        cur_size++;
    }
    
    void del(){
        cur_size--;
        list<pair<int, int> >::reverse_iterator it = entryList.rbegin();
        entryMap.erase(it->first);
        entryList.pop_back();
    }
private:
    list<pair<int, int> > entryList; //from Most(head) to Least(tail)
    unordered_map<int, list<pair<int, int> >::iterator> entryMap; //for getting, O(1)
    int max_size; //Total size
    int cur_size;
};
