/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR".
Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:
Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Note:
1. 1 <= len(start) = len(end) <= 10000.
2. Both start and end will only consist of characters in {'L', 'R', 'X'}.
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size())
            return false;
        int n = start.size();
        int R = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] == 'R') {
                R++;
            } else if (start[i] == 'L') {
                if (R != 0)
                    return false;
            }
            if (end[i] == 'R') {
                R--;
                if (R < 0)
                    return false;
            }
        }
        int L = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (start[i] == 'L') {
                L++;
            } else if (start[i] == 'R') {
                if (L != 0)
                    return false;
            }
            if (end[i] == 'L') {
                L--;
                if (L < 0)
                    return false;
            }
        }
        if (L != 0 || R != 0)
            return false;
        return true;
    }
};

class Solution {
public:
    bool canTransform(string start, string end) {
        int left = 0, right = 0;
        
        if (start.size() != end.size())
            return false;
        
        for (int i = 0; i < end.size(); i++) {
            if (start[i] == 'R') {
                right++;
                if (left > 0)
                    return false;
            }
            
            if (end[i] == 'L') {
                left++;   
                if (right > 0)
                    return false;
            }
            
            if (end[i] == 'R') {
                right--;
                if (right < 0)
                    return false;
            }
            
            if (start[i] == 'L') {
                left--;
                if (left < 0)
                    return false;
            }
        }
        
        if(right > 0 || left > 0)
            return false;
        return true;
        
    }
};
