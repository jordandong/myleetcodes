class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counter[26] = { 0 };
        bool used[26] = { 0 };
        string res;
        for (char &c : s)
            counter[c - 'a']++;

        for (char &c : s) {
            --counter[c - 'a'];
            if (used[c - 'a'])
                continue;
            while (res.size() && c < res.back() && counter[res.back() - 'a']) {
                used[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(c);
            used[c - 'a'] = true;
        }
        return res;
    }
};
