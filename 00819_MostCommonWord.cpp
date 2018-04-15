/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
 

Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
Different words in paragraph are always separated by a space.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        for (auto & c: paragraph) {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        istringstream iss(paragraph);
        string w, res = "";
        int mx_cnt = 0;
        while (iss >> w) {
            if (ban.find(w) == ban.end() && ++count[w] > mx_cnt) {
                res = w;
                mx_cnt = count[w];
            }
        }
        return res;
    }
};

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        string w, res = "";
        int mx_cnt = 0, s = 0, e = 0;

        paragraph += " ";
        while (e < paragraph.length()) {
            if (isalpha(paragraph[e])) {
                paragraph[e] = tolower(paragraph[e++]);
            } else {
                if (s == e) {
                    s++;
                    e++;
                } else {
                    w = paragraph.substr(s, e - s);
                    if (ban.find(w) == ban.end() && ++count[w] > mx_cnt) {
                        res = w;
                        mx_cnt = count[w];
                    }
                    e++;
                    s = e;
                }
            }
        }
        return res;
    }
};
