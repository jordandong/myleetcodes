/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Hide Tags Array Two Pointers
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
        int sz = num.size();
        int res = 0;
        if(sz < 3)
            return INT_MAX;
        
        sort(num.begin(), num.end());
        res = num[0] + num[1] + num[2];
        for(int i = 0; i < sz - 2; i++){
            int s = i + 1;
            int e = sz - 1;
            while(s < e){
            	int sum = num[i] + num[s] + num[e];
		if(sum == target)
		    return sum;
		if(abs(sum - target) < abs(res - target))
            	    res = sum;
            	if(sum > target)	  
		    e--;   
		else
		    s++;
            }
        }
        return res;
    }
};
