/*
Implement a MapSum class with insert, and sum methods.

For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

Example 1:
Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5
*/

class MapSum {
private:
    struct Node {
        Node () {
            memset(nodes, 0, sizeof(nodes));
            sum = 0;
        }
        int sum;
        struct Node *nodes[26];
    };
    
    struct Node* root;
    
    unordered_map<string, int> mp;

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new struct Node();
    }
    
    void insert(string key, int val) {
        int d = 0;
        int N = key.length();
        if (mp.find(key) != mp.end()) {
            d = val - mp[key];
        } else {
            d = val;
        }
        mp[key] = val;

        struct Node *node = root;
        for (int i = 0; i < N; i++) {
            int c = key[i] - 'a';
            if (!node->nodes[c])
                node->nodes[c] = new struct Node();
            node = node->nodes[c];
            node->sum += d;
        }
    }
    
    int sum(string prefix) {
        int N = prefix.length();
        struct Node *node = root;
        for (int i = 0; i < N; i++) {
            int c = prefix[i] - 'a';
            if (node->nodes[c])
                node = node->nodes[c];
            else
                return 0;
        }
        return node->sum;
    }
};

class MapSum {
private:
    struct Node {
        Node () {
            memset(nodes, 0, sizeof(nodes));
            sum = 0;
            val = 0;
        }
        int sum;
        int val;
        struct Node *nodes[26];
    };
    
    struct Node* root;

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new struct Node();
    }
    
    void insert(string key, int val) {
        int d = 0;
        insertHelper(root, key, 0, val, d);
    }
    
    void insertHelper(struct Node *root, string &key, int idx, int val, int &d) {
        int N = key.size();
        if (idx >= N)
            return;
        int i = key[idx] - 'a';
        if (!root->nodes[i])
            root->nodes[i] = new struct Node();
        if (idx == N - 1) {
            d = val - root->nodes[i]->val;
            root->nodes[i]->val = val;
        } else {
            insertHelper(root->nodes[i], key, idx + 1, val, d);
        }
        root->nodes[i]->sum += d;
    }
    
    int sum(string prefix) {
        int N = prefix.length();
        struct Node *node = root;
        for (int i = 0; i < N; i++) {
            int c = prefix[i] - 'a';
            if (node->nodes[c])
                node = node->nodes[c];
            else
                return 0;
        }
        return node->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
