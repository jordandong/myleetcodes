/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 

Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note: All inputs will be in lower-case.
Hide Tags Hash Table String
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            mp[copy].push_back(strs[i]);
        }

        auto it = mp.begin();
        while (it != mp.end()) {
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};
