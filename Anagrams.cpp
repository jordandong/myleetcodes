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
