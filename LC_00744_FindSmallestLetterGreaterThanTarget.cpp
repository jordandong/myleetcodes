/*
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target,
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target,
find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"

Note:
1. letters has a length in range [2, 10000].
2. letters consists of lowercase letters, and contains at least 2 unique letters.
3. target is a lowercase letter.
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ans = 'z' + 26;
        for (auto c: letters)
            ans = min((int)c + (c > target ? 0 : 26), ans);
        return ans > 'z' ? ans - 26 : ans;
    }
};

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char s = 'z' + 1, e = 'z' + 1;
        for (auto c: letters) {
            if (c < s)
                s = c;
            if (c > target)
                e = min(c, e);
        }
        
        if (e == 'z' + 1)
            return s;
        return e;
    }
};
