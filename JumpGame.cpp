//============================================================================
// Given an array of non-negative integers, you are initially positioned at
// the first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Determine if you are able to reach the last index.
//
// For example:
// A = [2,3,1,1,4], return true.
//
// A = [3,2,1,0,4], return false.
//============================================================================

#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        int next = 0;
        while (i <= next) {
            next = max(next, i + A[i]);
            if (next >= n - 1) return true;
            i++;
        }
        return false;
    }
};

int main() {
    return 0;
}




class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<0)
            return false;
        else if(n<=1)
            return true;
        else{
        
            for(int i=0;i<A[0];i++){
                if(canJump(A+i+1,n-i-1))
                    return true;
            }
        }
        return false;
    }
};
