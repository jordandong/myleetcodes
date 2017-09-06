/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string r = s;
        sort(r.begin(), r.end());
        reverse(r.begin(), r.end());
        
        for ( int i = 0; i < s.size(); ++i) {
            if (s[i] != r[i]) {
                char mx = s[i];
                int idx = i;
                for (int j = i; j < s.size(); j++) {
                    if (s[j] >= mx) { //the last biggest one
                        mx = s[j];
                        idx = j;
                    }
                }
                swap(s[i], s[idx]);
                return stoi(s);
            }
        }
        return num;
    }
};

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for ( int i = 0; i < s.size(); ++i) {
            for ( int j = i + 1; j < s.size(); ++j ) {
                swap(s[i], s[j]);
                num = max(num, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return num;   
    }
};
