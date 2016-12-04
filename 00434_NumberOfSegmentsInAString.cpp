/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

For example,

Input: "Hello, my name is John"

Output: 5
*/

class Solution {
public:
    int countSegments(string s) {
        bool hit = false;
        int res = 0;
        s.push_back(' ');
        for (auto c : s) {
            if (c == ' ') {
                if (hit) {
                    res++;
                    hit = false;
                }
            } else {
                hit = true;
            }
        }
        return res;
    }
};

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        int N = s.size();
        s.push_back(' ');
        for (int i = 0; i < N; i++)
            res += (s[i] != ' ' && s[i + 1] == ' ');
        return res;
    }
};
