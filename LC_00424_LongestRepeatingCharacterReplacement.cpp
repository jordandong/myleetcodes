/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:
Input:
s = "ABAB", k = 2
Output:
4
Explanation:
Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input:
s = "AABABBA", k = 1
Output:
4
Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        vector<int> cnt(26, 0);
        while (j < s.length()) {
            cnt[s[j++] - 'A']++;
            if (j - i - *max_element(cnt.begin(), cnt.end()) > k)
                cnt[s[i++] - 'A']--;
        }
        return j - i;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0, end = 0, maxCharCount = 0;
        int N = s.length(), res = 0;
        for (; end < N; end++) {
            counts[s[end] - 'A']++;
            maxCharCount = max(maxCharCount, counts[s[end] - 'A']);
            while (end - start - maxCharCount + 1 > k) {
                counts[s[start] - 'A']--;
                start++;
                for (int i = 0; i < 26; i++)
                    maxCharCount = max(maxCharCount, counts[i]);
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};
