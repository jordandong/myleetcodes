/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

Hide Tags Array Greedy
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0)
            return false;

        int end = 0;
        for(int start = 0; start <= end; start++){
            end = max(end, start + A[start]);
            if(end >= n - 1)
                return true;
        }
        return false;
    }
};

//recursion, cannnot pass TLE
class Solution {
public:
    bool canJump(int A[], int n) {
        if(n < 0)
            return false;
        else if(n <= 1)
            return true;
        else{
            for(int i = 0; i < A[0]; i++){
                if(canJump(A + i + 1, n - i - 1))
                    return true;
            }
        }
        return false;
    }
};
