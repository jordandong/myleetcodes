/*
Given a set of words (without duplicates), find all word squares you can build from them.
A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
b a l l
a r e a
l e a d
l a d y

Note:
1. There are at least 1 and at most 1000 words.
2. All words will have the exact same length.
3. Word length is at least 1 and at most 5.
4. Each word contains only lowercase English alphabet a-z.

Example 1:
Input:
["area","lead","wall","lady","ball"]
Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).

Example 2:

Input:
["abat","baba","atan","atal"]
Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]
Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    struct TrieNode {
        vector<int> indexs;
        vector<TrieNode*> children;
        TrieNode() {
            children.resize(26, NULL);
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* t = root;
            for (int j = 0; j < words[i].length(); j++) {
                if (!t->children[words[i][j] - 'a'])
                    t->children[words[i][j] - 'a'] = new TrieNode();
                t = t->children[words[i][j] - 'a'];
                t->indexs.push_back(i);
            }
        }
        return root;
    }
    
    void DFS(vector<string>& words, int level, TrieNode* root, vector<string> &sol, vector<vector<string>> &res) {
        if (level >= words[0].length()) {
            res.push_back(sol);
            return;
        }
        string str = "";
        for (auto& s : sol) 
            str += s[level];
        TrieNode* t = root;     
        for (int i = 0; i < str.size(); i++) { 
            t = t->children[str[i] - 'a'];
            if (!t)
            	return;
        }
        for (auto index : t->indexs) {
            sol.push_back(words[index]);
            DFS(words, level + 1, root, sol, res);
            sol.pop_back();
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        vector<string> sol;
        if (words.empty())
            return res;
        TrieNode* root = buildTrie(words);
        for (auto &word : words) {
            sol.push_back(word);
            DFS(words, 1, root, sol, res);
            sol.pop_back();
        }
        return res;
    }
};

/*
wall      Try words      wall                     wall                      wall
a...   => starting  =>   area      Try words      area                      area
l...      with "a"       le..   => starting  =>   lead      Try words       lead
l...                     la..      with "le"      lad.   => starting   =>   lady
                                                            with "lad"
*/

int main() {
	vector<string> data;
	//data = {"area","lead","wall","lady","ball"};
	//data = {"ball","area","lead","lady"};
	data = {"abat","baba","atan","atal"};
	Solution s;
	vector<vector<string>> res = s.wordSquares(data);
	for (auto e : res) {
		for (auto s : e)
			cout<<s<<endl;
		cout<<endl;
	}
	return 0;
}
