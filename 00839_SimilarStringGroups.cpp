/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of unique strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

Example 1:

Input: ["tars","rats","arts","star"]
Output: 2
Note:

A.length <= 2000
A[i].length <= 1000
A.length * A[i].length <= 20000
All words in A consist of lowercase letters only.
All words in A have the same length and are anagrams of each other.
The judging time limit has been increased for this question.
*/

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_map<string, string> parent;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            parent[A[i]] = A[i];
            for (int j = 0; j < i; j++) {
                if (isSimilar(A[i], A[j]))
                    UNION(A[i], A[j], parent);
            }
        }
        
        int ans = 0;
        for (auto it = parent.begin(); it != parent.end(); it++) {
            if (it->first == it->second)
                ans++;
        }
        return ans;
    }
    
private:
    bool isSimilar(string &a, string &b) {
        if (a.length() != b.length())
            return false;
        vector<int> idx;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i])
                idx.push_back(i);
        }
        return idx.size() == 2 && a[idx[0]] == b[idx[1]] && a[idx[1]] == b[idx[0]];
    }
    
    string FIND(string s, unordered_map<string,string> &parent) {
        if (parent[s] != s)
            return FIND(parent[s], parent);
        return s;
    }
    
    void UNION(string a, string b, unordered_map<string,string> &parent) {
        string pa = FIND(a, parent), pb = FIND(b, parent);
        parent[pa] = pb;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_map<string, string> parent;
        int n = A.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            parent[A[i]] = A[i];
            ans++;
            for (int j = 0; j < i; j++) {
                if (isSimilar(A[i], A[j]))
                    UNION(A[i], A[j], parent, ans);
            }
        }
        return ans;
    }
    
private:
    bool isSimilar(string &a, string &b) {
        if (a.length() != b.length())
            return false;
        vector<int> idx;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i])
                idx.push_back(i);
        }
        return idx.size() == 2 && a[idx[0]] == b[idx[1]] && a[idx[1]] == b[idx[0]];
    }
    
    string FIND(string s, unordered_map<string,string> &parent) {
        if (parent[s] != s)
            return FIND(parent[s], parent);
        return s;
    }
    
    void UNION(string a, string b, unordered_map<string,string> &parent, int &ans) {
        string pa = FIND(a, parent), pb = FIND(b, parent);
        if (pa != pb)
            ans--;
        parent[pa] = pb;
    }
};
