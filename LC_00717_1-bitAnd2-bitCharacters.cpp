/*
We have two special characters. The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits.
Return whether the last character must be a one-bit character or not.
The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.

Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.

Note:
1. 1 <= len(bits) <= 1000.
2. bits[i] is always 0 or 1.
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = 0;
        while (i < n - 1)
            i += (bits[i] + 1); 
        return i == n - 1;
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int N = bits.size();
        if (N == 0)
            return false;
        int i = 0;
        while (i < N) {
            if (i == N - 1)
                return (bits[i] == 0);
            
            if (bits[i++] == 1)
                i++;
        }
        return false;
    }
};
