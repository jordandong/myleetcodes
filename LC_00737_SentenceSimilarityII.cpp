/*
Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar,
if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive.
For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Also, a word is always similar with itself.
For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Note:
1. The length of words1 and words2 will not exceed 1000.
2. The length of pairs will not exceed 2000.
3. The length of each pairs[i] will be 2.
4. The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int m = words1.size(), n = words2.size();
        if(m != n)
            return false;
        unordered_map<string, string> parent;
        for (auto p : pairs) {
            merge(parent, p.first, p.second);
        }
        for (int i = 0; i < m; i++) {
            if (words1[i] == words2[i] || find(parent, words1[i]) == find(parent, words2[i]))
                continue;
            return false;
        }
        return true;    
    }
private:
    string find (unordered_map<string, string> &parent, string child) {
        if (parent.find(child) == parent.end() || parent[child] == child) {
            parent[child] = child;
            return child;
        }
        return find(parent, parent[child]);
    }
    
    void merge (unordered_map<string, string> &parent, string x, string y) {
        string xset = find(parent, x);
        string yset = find(parent, y);
        parent[xset] = yset;
    }
};
