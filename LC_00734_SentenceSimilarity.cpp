/*
Given two sentences words1, words2 (each represented as an array of strings),
and a list of similar word pairs pairs, determine if two sentences are similar.

For example, "great acting skills" and "fine drama talent" are similar,
if the similar word pairs are pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is not transitive.
For example, if "great" and "fine" are similar, and "fine" and "good" are similar, "great" and "good" are not necessarily similar.

However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself.
For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words.
So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

Note:
1. The length of words1 and words2 will not exceed 1000.
2. The length of pairs will not exceed 2000.
3. The length of each pairs[i] will be 2.
4. The length of each words[i] and pairs[i][j] will be in the range [1, 20].
*/

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int m = words1.size(), n = words2.size();
        if(m != n)
            return false;
        unordered_map<string, set<string>> mp;
        for (auto p : pairs) {
            mp[p.first].insert(p.second);
            mp[p.second].insert(p.first); //if this is added, second if is not necessary #
        }
        for (int i = 0; i < m; i++) {
            if (words1[i] == words2[i])
                continue;
            if (mp.find(words1[i]) != mp.end()) {
                if (mp[words1[i]].find(words2[i]) != mp[words1[i]].end())
                    continue;
            }
            
            if (mp.find(words2[i]) != mp.end()) { //This is not necessary if mp is added before
                if (mp[words2[i]].find(words1[i]) != mp[words2[i]].end())
                    continue;
            }
            return false;
        }
        return true;
    }
};
