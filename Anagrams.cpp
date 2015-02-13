/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Hide Tags Hash Table String
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            mp[copy].push_back(strs[i]);
        }

        auto it = mp.begin();
        while (it != mp.end()) {
            vector<string> &data = it->second;
            if(data.size() > 1)
                for(int i = 0; i < data.size(); i++)
                    res.push_back(data[i]);
            it++;
        }
        return res;
    }
};

//Cannnot pass TLE
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, map<char, int> > strCharsMap;
        map<map<char, int>, int> charsCountMap;
        vector<string> res;
        
        for(int i = 0; i < strs.size(); ++i) {
            map<char, int> map;
            for(int j = 0; j < strs[i].size(); ++j)
                map[strs[i][j]] += 1;
            strCharsMap[strs[i]] = map;
            charsCountMap[map] += 1;
        }
        
        for(int i = 0; i < strs.size(); ++i) {
            if(charsCountMap[strCharsMap[strs[i]]] > 1)
                res.push_back(strs[i]);
        }
        return res;
    }
};
