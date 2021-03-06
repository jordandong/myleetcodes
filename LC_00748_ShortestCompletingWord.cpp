/*
Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate.
Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times.
For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.

Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.

Note:
1. licensePlate will be a string with length in range [1, 7].
2. licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
3. words will have a length in the range [10, 1000].
4. Every words[i] will consist of lowercase letters, and have length in range [1, 15].
*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> counts(26, 0);
        int count = 0;
        for (char c : licensePlate) {
            if (isalpha(c)) {
                counts[tolower(c) - 'a']++;
                count++;
            }
        }
        string res(16, '*');
        for (string w : words) {
            if (w.length() >= res.length())
                continue;
            vector<int> cnts(26, 0);
            int cnt = 0;
            for (int i = 0; i < w.length(); i++) {
                char c = w[i];
                if (counts[c - 'a'] > 0 && cnts[c - 'a'] < counts[c - 'a']) {
                    cnts[c - 'a']++;
                    if (++cnt == count && w.length() < res.length())
                        res = w;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& words) {
        multiset<char> need;
        for (char c : s) {
            if (isalpha(c))
                need.insert(tolower(c));
        }
        string res(16, ' ');
        for (string w : words) {
            if (w.size() < res.size()) {
                multiset<char> have(w.begin(), w.end());
                if (includes(have.begin(), have.end(), need.begin(), need.end()))
                    res = w;
            }
        }
        return res;
    }
};
