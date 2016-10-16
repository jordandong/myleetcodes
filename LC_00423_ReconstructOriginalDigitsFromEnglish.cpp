/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
1. Input contains only lowercase English letters.
2. Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
3. Input length is less than 50,000.

Example 1:
Input: "owoztneoer"
Output: "012"

Example 2:
Input: "fviefuro"
Output: "45"

Hide Tags Math
*/

class Solution {
public:
    string originalDigits(string s) {
        vector<int> res(10, 0);
        vector<int> cache(26, 0);
        for (auto ch : s) 
            cache[ch - 'a']++;
        res[0] = cache['z' - 'a']; //z*ero4
        res[2] = cache['w' - 'a']; //tw*o4
        res[4] = cache['u' - 'a']; //fo4u*r
        res[6] = cache['x' - 'a']; //s2ix*
        res[8] = cache['g' - 'a']; //e3ig*h1t
        res[3] = cache['h' - 'a'] - res[8]; //th1-ree
        res[7] = cache['s' - 'a'] - res[6]; //s2ev3en5
        res[5] = cache['v' - 'a'] - res[7]; //fiv3e
        res[1] = cache['o' - 'a'] - (res[0] + res[2] + res[4]); //o4n5e
        res[9] = (cache['n' - 'a'] - (res[1] + res[7])) / 2; //n5ine
        string ans = "";
        for (int i = 0; i < 10; i++) 
            if (res[i]) 
                ans += string(res[i], i + '0');
        return ans;
    }
};
