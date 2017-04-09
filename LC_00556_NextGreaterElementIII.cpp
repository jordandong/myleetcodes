/*
Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n.
If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21

Example 2:
Input: 21
Output: -1

Hide Tags String
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int N = num.length();
        if (N < 2)
        	return -1;
        
        int i = N - 2;
        while (i >= 0 && num[i] >= num[i + 1])
        	i--;
        
        if (i == -1)
            return -1;
               
        int j = N - 1;
        while (j > i && num[j] <= num[i])
        	j--;
        	
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());

        long res = stol(num);
        return (res > INT_MAX) ? -1 : res;
    }
};
