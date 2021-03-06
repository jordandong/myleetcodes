/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note:
1. The input strings only contain lower case letters.
2. The length of both given strings is in range [1, 10,000].

Hide Tags Two Pointers
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m(256, 0);
        int N = s1.size();
        if (N > s2.size())
            return false;

        for(int i = 0; i < N; ++i)
            m[s1[i]]++;
        int cnt = 0;
        for (int i = 0, j = 0; j < s2.size(); j++) {
            if (m[s2[j]]-- > 0)
                cnt++;

            while (cnt == N) {
                if (j + 1 - i == N)
                    return true;
                if (++m[s2[i++]] > 0)
                    cnt--;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(256, 0), m2(256, 0);
        int N = s1.size();
        if (N > s2.size())
            return false;
        for(int i = 0; i < N; ++i) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        if(m1 == m2)
            return true;
        for(int i = N; i < s2.size(); ++i) {
            m2[s2[i]]++;
            m2[s2[i - N]]--;
            if(m1 == m2)
                return true;
        }
        return false;
    }
};
