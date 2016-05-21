/*
Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string cur;
        generateAbbreviationsHelper(word, 0, &cur, &res);
        return res;
    }

    void generateAbbreviationsHelper(const string& word, int i, string *cur, vector<string> *res) {
        if (i == word.length()) {
            res->push_back(*cur);
            return;
        }
        cur->push_back(word[i]);
        generateAbbreviationsHelper(word, i + 1, cur, res);
        cur->pop_back();
        if (cur->empty() || !isdigit(cur->back())) {
            for (int l = 1; i + l <= word.length(); ++l) {
                cur->append(to_string(l));
                generateAbbreviationsHelper(word, i + l, cur, res);
                cur->resize(cur->length() - to_string(l).length());
            }
        }
    }
};
