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
