/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        vector<set<string>> bucket(words.size() + 1, set<string>{});
        /*
        Internally, the elements in a set are always sorted following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
        */
        for (string s: words)
            m[s]++;
        for (auto it: m)
            bucket[it.second].insert(it.first);
        for (int i = words.size(); i > 0; i--) {
            for (string s: bucket[i]) {
                res.push_back(s);
                if (res.size() == k)  
                    return res;
            }
        }
        return res;
    }
};

class Solution {
public:
    struct comp {
        bool operator() (pair<string, int> &a, pair<string, int> &b) {
            if (a.second != b.second)
                return a.second > b.second;
            else
                return a.first < b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq;
        unordered_map<string, int> dict;
        vector<string> res;
        for(int i = 0; i < words.size(); i++)
            dict[words[i]]++;
        for(auto p = dict.begin(); p != dict.end(); p++) {
            pq.push({p->first, p->second});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
