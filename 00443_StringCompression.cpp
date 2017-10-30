/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".

Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        if (N == 0)
            return N;
        int cnt = 1, base = 1, i = 0, j = 1;
        char x = chars[0];
        while (j <= N) {
            //same char
            if (j < N && chars[j] == x) {
                if (++cnt >= base * 10)
                    base *= 10;
                j++;
                continue;
            }
            //new char
            chars[i++] = x;
            if (j < N)
                x = chars[j];
            if (cnt != 1) {
                while (base) {
                    chars[i++] = (cnt / base + '0');
                    cnt %= base;
                    base /= 10;
                }
            }
            cnt = 1;
            base = 1;
            j++;
        }
        return i;
    }    
};
