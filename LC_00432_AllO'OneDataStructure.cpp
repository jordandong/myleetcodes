/*
Implement a data structure supporting the following operations:
1. Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
2. Dec(Key) - Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. Key is guaranteed to be a non-empty string. If the key does not exist, this function does nothing.
3. GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
4. GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".

Challenge: Perform all these in O(1) time complexity.
Hide Tags Design
*/

class AllOne {
private:
    struct ListNode {
        list<string> strs;
        int val;
        ListNode(const string &s, int x) : strs({s}), val(x) {}
    };

    unordered_map<string, pair<list<ListNode>::iterator, list<string>::iterator>> strmap;
    list<ListNode> matrix;

public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc (string key) {
        if (strmap.find(key) == strmap.end()) {
            if (matrix.empty() || matrix.back().val != 1) { //adding new key with val(1) at the bottom
                auto newrow = matrix.emplace(matrix.end(), key, 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else { //adding new key with val(1) into the exsiting row
                auto newrow = --matrix.end();
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
        } else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            auto lastrow = row;
            --lastrow;
            //if (lastrow == matrix.end() || lastrow->val != row->val + 1) {
            if (row == matrix.begin() || lastrow->val != row->val + 1) { //sorted by values from bigger to smaller
                auto newrow = matrix.emplace(row, key, row->val + 1); //insert different val with new string list
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else { //update existing val string list
                auto newrow = lastrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col); //remove the key from old string list
            if (row->strs.empty())
                matrix.erase(row);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (strmap.find(key) == strmap.end()) {
            return;
        } else {
            auto row = strmap[key].first;
            auto col = strmap[key].second;
            if (row->val == 1) {
                row->strs.erase(col);
                if (row->strs.empty()) {
                    matrix.erase(row);
                    strmap.erase(key);
                }
                return;
            }

            auto nextrow = row;
            ++nextrow;
            if (nextrow == matrix.end() || nextrow->val != row->val - 1) {
                auto newrow = matrix.emplace(nextrow, key, 1);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            } else {
                auto newrow = nextrow;
                newrow->strs.push_front(key);
                strmap[key] = make_pair(newrow, newrow->strs.begin());
            }
            row->strs.erase(col);
            if (row->strs.empty())
                matrix.erase(row);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (matrix.empty())
            return "";
        else
            return matrix.front().strs.front();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (matrix.empty())
            return "";
        else
            return matrix.back().strs.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
