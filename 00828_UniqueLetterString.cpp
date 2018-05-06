/*
A character is unique in string S if it occurs exactly once in it.

For example, in string S = "LETTER", the only unique characters are "L" and "R".

Let's define UNIQ(S) as the number of unique characters in string S.

For example, UNIQ("LETTER") =  2.

Given a string S, calculate the sum of UNIQ(substring) over all non-empty substrings of S.

If there are two or more equal substrings at different positions in S, we consider them different.

Since the answer can be very large, retrun the answer modulo 10 ^ 9 + 7.

 

Example 1:

Input: "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:

Input: "ABA"
Output: 8
Explanation: The same as example 1, except uni("ABA") = 1.
 

Note: 0 <= S.length <= 10000.
*/

//T : O(N ^ 2), S : O(1)
class Solution {
public:
    int uniqueLetterString(string S) {
        int ans = 0, L = S.size(), mod = 1000000007;
        for (int i = 0; i < L; i++) {
            int i0 = i, i1 = i;
            while (i0 - 1 >= 0 && S[i0 - 1] != S[i])
                i0--;
            while (i1 + 1 < L && S[i1 + 1] != S[i])
                i1++;
            ans += ((i - i0 + 1) * (i1 - i + 1)) % mod;
        }
        return ans;
    }
};

//T : O(N), S : O(N)
class Solution {
public:
    int uniqueLetterString(string S) {
        int ans = 0, L = S.size(), mod = 1000000007;
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < L; i++) {
            if (mp.find(S[i]) == mp.end()) {
                mp[S[i]].push_back(-1);
            } else {
                int n = mp[S[i]].size();
                int k = mp[S[i]][n - 2], j = mp[S[i]][n - 1];
                ans += ((i - j) * (j - k)) % mod; //count of previous unique char
            }
            mp[S[i]].push_back(i);
        }
        
        //count last unique char
        for (auto v : mp) {
            int n = v.second.size();
            int k = v.second[n - 2], j = v.second[n - 1];
            ans += ((L - j) * (j - k)) % mod;
        }
        return ans;
    }
};
