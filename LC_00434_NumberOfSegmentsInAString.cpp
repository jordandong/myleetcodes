/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:
Input: "Hello, my name is John"
Output: 5

Hide Tags String
*/

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
