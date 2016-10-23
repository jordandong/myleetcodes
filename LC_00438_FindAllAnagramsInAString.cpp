/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"
Output:
[0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"
Output:
[0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Hide Tags Hash Table
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, mp(26, 0);
        if (s.length() == 0 || p.length() == 0)
            return res;
        for (char c : p)
            mp[c - 'a']++; //target string distribution

        int left = 0, right = 0, count = 0;
        while (right < s.length()) {
            //move right everytime, if the character exists in p's map
            //value >= 1 means the character is existing in p
            if (mp[s[right++] - 'a']-- >= 1)
                count++; 
        
            if (count == p.length())
                res.push_back(left);

            //++ to reset the map because we kicked out the left
            //only decrease the count if the character is in p
            //the count >= 0 indicate it was original in the hash, cuz it won't go below 0
            if (right - left == p.length() && mp[s[left++] - 'a']++ >= 0)
                count--;
        }
        return res;
    }
};
