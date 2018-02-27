/*
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously.
We want to permute the characters of T so that they match the order that S was sorted.
More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.

Note:
1. S has length at most 26, and no character is repeated in S.
2. T has length at most 200.
3. S and T consist of lowercase letters only.
*/

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> dir(26, S.size());
        for (int i = 0; i < S.size(); i++)
            dir[S[i] - 'a'] = i;

        sort(T.begin(), T.end(),
             [&](char a, char b) { return dir[a - 'a'] < dir[b - 'a']; });
        return T;
    }
};

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> smap(26, -1); //Order map
        for(int i = 0; i < S.size(); i++)
            smap[i] = S[i] - 'a';
        
        vector<int> tmap(26, 0);  //chars map
        for(int i = 0; i < T.size(); i++)
            tmap[T[i] - 'a']++;
        
        string res;
        for(int i = 0; i < 26; i++) {
            if(smap[i] >= 0) {   //If the char appears in S, we need to sort it
                res += string(tmap[smap[i]], smap[i] + 'a');
                tmap[smap[i]] = 0;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(tmap[i])   //Otherwise, append it to the end of the "sorted" string
                res += string(tmap[i], i + 'a');
        }
        return res;
    }
};
