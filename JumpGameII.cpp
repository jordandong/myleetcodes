/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Hide Tags Array Greedy
*/

//T:O(n)
class Solution {
public:
    int jump(int A[], int n) {
        int step = 0;
        int start =0;
        int end = 0;
        int next = 0;
        while (end < n-1){
            step++;
            for (int i = start; i <= end; i++)
                next = max(next, A[i] + i);//for step, can reach the max(next)
            start = end + 1;
            if (next <= end)
                return -1;
            end = next;
        }
        return step;
    }
};

//T:O(N^2), Cannot Pass large set test cases (TLE)
class Solution {
public:
    int jump(int A[], int n) {
    	int count = 0;
        int end = n-1;
        while(end){
            for(int i = 0; i < end; i++){
            	if((A[i] + i) >= end){
            	    count++;
            	    end = i;
            	    break;
            	}
            }
        }
        return count;
    }
};
