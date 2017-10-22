/*
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int count = 1, a = 0, b = 0;
        
        for (int i = 0; i < A.length(); i++) {
            b = 0;
            if (A[i] != B[b])
                continue;
            a = i;
            while (b < B.length() && a < A.length() && A[a] == B[b]) {
                if (++b == B.length())
                    return count;
                if (++a == A.length()) {
                    a = 0;
                    count++;
                }
            }
        }
        return -1;
    }
};
