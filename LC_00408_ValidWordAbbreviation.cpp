/*
Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.

A string such as "word" contains only the following valid abbreviations:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
Notice that only the above abbreviations are valid abbreviations of the string "word". 
Any other string is not a valid abbreviation of "word".

Note:
Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.

Example 1:
Given s = "internationalization", abbr = "i12iz4n":

Return true.
Example 2:
Given s = "apple", abbr = "a2e":

Return false.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, digit = 0;
        for (const auto &c : abbr) {
            if (isdigit(c)) {
                if (digit == 0 && c == '0') {
                    return false;
                } 
                digit *= 10;
                digit += c - '0';
            } else {
                if (digit) {
                    i += digit;
                    digit = 0;
                }
                if (i >= word.length() || word[i++] != c) {
                    return false;
                }
            }
        }
        if (digit) {
            i += digit;
        }
        return i == word.length();
    }
};

int main() {
	Solution s;
	cout<<s.validWordAbbreviation("asdwewqe", "a3e2e")<<endl;
	cout<<s.validWordAbbreviation("foot", "f4")<<endl;
	return 0;
}

