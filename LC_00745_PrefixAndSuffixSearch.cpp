/*
Given many words, words[i] has weight i.
Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix).
It will return the word with given prefix and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1

Note:
1. words has length in range [1, 15000].
2. For each test case, up to words.length queries WordFilter.f may be made.
3. words[i] has length in range [1, 10].
4. prefix, suffix have lengths in range [0, 10].
5. words[i] and prefix, suffix queries consist of lowercase letters only.
*/

class WordFilter {
private:
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string> words) {
        for (int ii = 0; ii < words.size(); ii++) {
            for (int i = 0; i <= words[ii].length(); i++) {
                for (int j = 0; j <= words[ii].length(); j++) {
                    mp[words[ii].substr(0, i) + "#" + words[ii].substr(j)] = ii;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        auto it = mp.find(prefix + "#" + suffix);
        if (it == mp.end())
            return -1;
        return it->second;
    }
};

class WordFilter {
private:
    unordered_map<string, vector<int>> prefix_mp, suffix_mp;
public:
    WordFilter(vector<string> words) {
        for (int ii = 0; ii < words.size(); ii++) {
            for (int i = 0; i <= words[ii].length(); i++)
                prefix_mp[words[ii].substr(0, i)].push_back(ii);
            for (int j = 0; j <= words[ii].length(); j++)
                suffix_mp[words[ii].substr(j)].push_back(ii);
        }
    }

    int f(string prefix, string suffix) {
        auto prefix_it = prefix_mp.find(prefix);
        if (prefix_it == prefix_mp.end())
            return -1;
        auto suffix_it = suffix_mp.find(suffix);
        if (suffix_it == suffix_mp.end())
            return -1;
        
        int i = prefix_it->second.size() - 1, j = suffix_it->second.size() - 1;
        while (i >= 0 && j >= 0) {
            int p = prefix_it->second[i], s = suffix_it->second[j];
            if (p == s)
                return p;
            if (p < s)
                j--;
            else
                i--;
        }
        return -1;
    }
};

class WordFilter {
private:
    vector<string> data;
    
    bool beginWith (string w, string s) {
        int i = 0, j = 0;
        while (i < w.length() && j < s.length()) {
            if (w[i++] != s[j++])
                return false;
        }
        return true;
    }
    
    
    bool endWith (string w, string s) {
        int i = w.length() - 1, j = s.length() - 1;
        while (i >= 0 && j >= 0) {
            if (w[i--] != s[j--])
                return false;
        }
        return true;
    }

public:
    WordFilter(vector<string> words) {
        data = words;
    }

    int f(string prefix, string suffix) {
        for (int i = data.size() - 1; i >= 0; i--) {
            if (beginWith(data[i], prefix) && endWith(data[i], suffix))
                return i;
        }
        return -1;
    }
};

class Trie {
private:
    vector<int> words; // index of words
    vector<Trie *> children;
public:
    Trie() {
        children = vector<Trie *>(26, NULL);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i])
                delete children[i];
        }
    }
    
    void add(const string &word, int begin, int index) {
        words.push_back(index);
        if (begin < word.length()) {
            if (!children[word[begin] - 'a'])
                children[word[begin] - 'a'] = new Trie();
            children[word[begin] - 'a']->add(word, begin + 1, index);
        }
    }
    
    vector<int> find(const string &prefix, int begin) {
        if (begin == prefix.length()) {
            return words;
        } else {
            if (!children[prefix[begin] - 'a']) {
                return {};
            } else {
                return children[prefix[begin] - 'a']->find(prefix, begin + 1);
            }
        }
    }
};

class WordFilter {
private:
    Trie *forwardTrie, *backwardTrie;
public:
    WordFilter(vector<string> words) {
        forwardTrie = new Trie();
        backwardTrie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            forwardTrie->add(word, 0, i);
            reverse(word.begin(), word.end());
            backwardTrie->add(word, 0, i);
        }
    }
    
    int f(string prefix, string suffix) {
        auto forwardMatch = forwardTrie->find(prefix, 0);
        reverse(suffix.begin(), suffix.end());
        auto backwardMatch = backwardTrie->find(suffix, 0);
        // search from the back
        auto fIter = forwardMatch.rbegin(), bIter = backwardMatch.rbegin();
        while (fIter != forwardMatch.rend() && bIter != backwardMatch.rend()) {
            if (*fIter == *bIter) {
                return *fIter;
            } else if (*fIter > *bIter) {
                fIter++;
            } else {
                bIter++;
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
