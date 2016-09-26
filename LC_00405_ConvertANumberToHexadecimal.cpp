/*
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
https://en.wikipedia.org/wiki/Two%27s_complement

Note:
1. All letters in hexadecimal (a-f) must be in lowercase.
2. The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0';
   otherwise, the first character in the hexadecimal string will not be the zero character.
3. The given number is guaranteed to fit within the range of a 32-bit signed integer.
4. You must not use any method provided by the library which converts/formats the number to hex directly.

Example 1:
Input:
26
Output:
"1a"

Example 2:
Input:
-1
Output:
"ffffffff"

Hide Tags Bit Manipulation
*/

class Solution {
public:
    string toHex(int num) {
        string res = "";
        int round = 8;
        while (round-- > 0) {
            int data = num & 0xf0000000;
            num <<= 4;
            data >>= 28;
            data &= 0x0000000f;
            if (data == 0 && res == "")
                continue;
            if (data > 9)
                res += ('a' + data - 10);
            else
                res += ('0' + data);
        }
        return res == "" ? "0" : res;
        
    }
};

class Solution {
public:
    string toHex(int num) {
        string res = "";
        int mask = 0x0000000f;
        int round = 8;
        while (round-- > 0 && num) {
            int data = num & mask;
            string s = "";
            if (data > 9)
                s += ('a' + data - 10);
            else
                s += ('0' + data);
            res = s + res;
            num >>= 4;
        }
        return res == "" ? "0" : res; 
        
    }
};
