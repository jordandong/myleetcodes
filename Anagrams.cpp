//============================================================================
// Given an array of strings, return all groups of strings that are anagrams.
//
// Note: All inputs will be in lower-case.
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > buffer;
        for (int i = 0; i < strs.size(); i++) {
            string copy(strs[i]);
            sort(copy.begin(), copy.end());
            buffer[copy].push_back(strs[i]);
        }
        vector<string> res;
        map<string, vector<string> >::iterator it = buffer.begin();
        while (it != buffer.end()) {
            vector<string> sub = it->second;
            if (sub.size() > 1)
                for (int i = 0; i < sub.size(); i++)
                    res.push_back(sub[i]);
            it++;
        }
        return res;
    }
};

int main() {
    return 0;
}


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, map<char, int> > strCharsMap;
        map<map<char, int>, int> charsCountMap;
        for(int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            map<char, int> map;
            for(int j = 0; j < s.size(); ++j) {
                char c = s[j];
                map[c] += 1;
            }
            
            strCharsMap[s] = map;
            charsCountMap[map] += 1;
        }
        
        vector<string> sol;
        for(int i = 0; i < strs.size(); ++i) {
            if(charsCountMap[strCharsMap[strs[i]]] > 1)
                sol.push_back(strs[i]);
        }
        return sol;
    }
};
