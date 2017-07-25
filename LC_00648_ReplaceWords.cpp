/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor.
For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence.
You need to replace all the successor in the sentence with the root forming it.
If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Note:
1. The input will only have lower-case letters.
2. 1 <= dict words number <= 1000
3. 1 <= sentence words number <= 1000
4. 1 <= root length <= 100
5. 1 <= sentence words length <= 1000
*/

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        set<string> mp;
        for (auto &d : dict)
            mp.insert(d);
        string res;
        for (int i = 0, j = 0; j <= sentence.length(); j++) {
            if (j == sentence.length() || sentence[j] == ' ') {
                res += sentence.substr(i, j - i + 1);
                i = j + 1;
                continue;
            }
            string h = sentence.substr(i, j - i + 1);
            if (mp.find(h) != mp.end()) {
                res += h;
                while (j < sentence.length() && sentence[j] != ' ') {
                    j++;
                }
                if (j != sentence.length())
                    res += " ";
                i = j + 1;
            }
        }
        return res;
        
    }
};

class Solution {
private:
    struct TrieNode {
        bool end;
        TrieNode* next[26];
        TrieNode () {
            memset(next, 0, sizeof(TrieNode*)*26);
            end = false;
        };
    };
    TrieNode* root;

public:
    void insert(string s) {
        TrieNode* tmp = root;
        for (int i = 0; i < s.length(); i++) {
            if (!tmp->next[s[i] - 'a'])
                tmp->next[s[i] - 'a'] = new TrieNode();
            tmp = tmp->next[s[i] - 'a'];
        }
        tmp->end = true;
    }
    
    string search (string s) {
        string res = "";
        TrieNode* tmp = root;
        for (int i = 0; i < s.length(); i++) {
            if (tmp->next[s[i] - 'a']) {
                res += s[i];
                tmp = tmp->next[s[i] - 'a']; 
                if (tmp->end)
                    return res;
            } else {
                return s;
            }
        }
        return s;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        for (auto &d : dict)
            insert(d);
        string res;
        int i = 0, j = 0;
        
        while (i < sentence.length() && j <= sentence.length()) {
            if (j == sentence.length() || sentence[j] == ' ') {
                res += search(sentence.substr(i, j - i));
                while (j != sentence.length() && sentence[j] == ' ') {
                    j++;
                    res +=" ";
                }
                i = j;
            } else {
                j++;
            }
        }
        return res;
    }
};
