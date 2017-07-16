/*
Design a search autocomplete system for a search engine.
Users may input a sentence (at least one word and end with a special character '#').
For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:
1. The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
2. The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one).
   If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
3. If less than 3 hot sentences exist, then just return as many as you can.
4. When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

Your job is to implement the following functions:
The constructor function:
AutocompleteSystem(String[] sentences, int[] times): This is the constructor.
The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:
List<String> input(char c): The input c is the next character typed by the user.
The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#').
Also, the previously typed sentence should be recorded in your system.
The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.

Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2]) 
The system have already tracked down the following sentences and their corresponding times: 
"i love you" : 5 times 
"island" : 3 times 
"ironman" : 2 times 
"i love leetcode" : 2 times 

Now, the user begins another search: 
Operation: input('i') 
Output: ["i love you", "island","i love leetcode"]
Explanation: 
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree.
Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman".
Also we only need to output top 3 hot sentences, so "ironman" will be ignored. 

Operation: input(' ') 
Output: ["i love you","i love leetcode"] 
Explanation: 
There are only two sentences that have prefix "i ". 

Operation: input('a') 
Output: [] 
Explanation: 
There are no sentences that have prefix "i a". 

Operation: input('#') 
Output: [] 
Explanation: 
The user finished the input, the sentence "i a" should be saved as a historical sentence in system.
And the following input will be counted as a new search. 

Note:
1. The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
2. The number of complete sentences that to be searched won't exceed 100.
   The length of each sentence including those in the historical data won't exceed 100.
3. Please use double-quote instead of single-quote when you write test cases even for a character input.
4. Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases.
   Please see here for more details.
*/

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        int n = sentences.size();
        for (int i = 0; i < n; i++)
            mp[sentences[i]] = times[i];
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            if (!buffer.empty()) {
                mp[buffer]++;
                buffer = "";
            }
            return {};
        }
        
        buffer += c;
        vector<pair<int, string> > res;
        auto pa = mp.lower_bound(buffer);
        auto pb = mp.upper_bound(buffer + "|");
        for (auto it = pa; it != pb; ++it)
            res.push_back({-it->second, it->first});
        sort(res.begin(), res.end());
        
        vector<string> ans;
        int cnt = 0;
        for (const auto& item: res) {
            ans.push_back(item.second);
            cnt++;
            if (cnt >= 3) {
                break;
            }
        }
        return ans;
    }
private:
    string buffer;
    map<string, int> mp;
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++)
            insert(sentences[i], times[i]);
        buf = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(buf, 1);
            buf = "";
            return {};
        }

        buf += c;
        vector<pair<int, string>> res;
        vector<string> ans;
        search(buf, res);
        sort(res.begin(), res.end());
        for (auto e : res) {
            ans.push_back(e.second);
            if (ans.size() == 3)
                return ans;
        }
        return ans;
    }
    
private:
    struct TrieNode {
        TrieNode *node[27];
        int freq;
        string s;
        TrieNode() {
            memset(node, 0, sizeof(node));
            freq = 0;
            s = "";
        }
    };
    TrieNode* root;
    string buf;

    void insert(string &s ,int freq) {
        TrieNode *t = root;
        for (int i = 0; i < s.length(); i++) { 
            int idx = (s[i] == ' ' ? 26 : (s[i] - 'a'));
            if (t->node[idx] == NULL) 
                t->node[idx] = new TrieNode();
            t = t->node[idx];
        }
        t->freq += freq;
        t->s = s;
    }
    
    void search(string &key, vector<pair<int, string>> &res) {
        TrieNode *t = root;
        for (int i = 0; i < key.length(); i++) { 
            int idx = (key[i] == ' ' ? 26 : (key[i] - 'a'));
            if (NULL == t->node[idx])
                return;
            t = t->node[idx];
        }
        get(t, res);
    }
    
    void get(TrieNode* t, vector<pair<int, string>> &res) {
        if (t->freq)
            res.push_back({-t->freq, t->s});
        for (int i = 0; i <= 26; i++) {
            if (t->node[i])
                get(t->node[i], res);
        }
    }
};

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++)
            insert(sentences[i], times[i]);
        buf = "";
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            insert(buf, 1);
            buf = "";
            return {};
        }

        buf += c;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> res;
        vector<string> ans;
        search(buf, res);
        while (!res.empty()) {
            ans.insert(ans.begin(), res.top().second);
            res.pop();
        }
        return ans;
    }
    
private:
    struct cmp {
        bool operator() (pair<int, string> &a, pair<int, string> &b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    struct TrieNode {
        TrieNode *node[27];
        int freq;
        string s;
        TrieNode() {
            memset(node, 0, sizeof(node));
            freq = 0;
            s = "";
        }
    };
    
    TrieNode* root;
    string buf;

    void insert(string &s ,int freq) {
        TrieNode *t = root;
        for (int i = 0; i < s.length(); i++) { 
            int idx = (s[i] == ' ' ? 26 : (s[i] - 'a'));
            if (t->node[idx] == NULL) 
                t->node[idx] = new TrieNode();
            t = t->node[idx];
        }
        t->freq += freq;
        t->s = s;
    }
    
    void search(string &key, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> &res) {
        TrieNode *t = root;
        for (int i = 0; i < key.length(); i++) { 
            int idx = (key[i] == ' ' ? 26 : (key[i] - 'a'));
            if (NULL == t->node[idx])
                return;
            t = t->node[idx];
        }
        get(t, res);
    }
    
    void get(TrieNode* t, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> &res) {
        if (t->freq)
            res.push({t->freq, t->s});
        if (res.size() > 3)
            res.pop();
        for (int i = 0; i <= 26; i++) {
            if (t->node[i])
                get(t->node[i], res);
        }
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
