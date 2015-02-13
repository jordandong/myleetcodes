/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

Hide Tags Divide and Conquer Array Dynamic Programming
*/

//T: O(N)
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0)
            return -1;
        int sum = 0;
        int res = A[0];
        for(int i = 0; i < n; i++){
            sum += A[i];
            res = max(res, sum);
            if(sum < 0)
                sum = 0;
        }
        return res;
    }
};

//T: O(N*logN)
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n <= 0)
            return -1;
        return maxSubArrayHelper(A, 0, n-1);
    }
    
    int maxSubArrayHelper(int A[], int lo, int hi){
        /* One element in the array */
        if (lo == hi) 
            return A[lo];
        /* Middle element of the array */   
        int mid = lo + (hi - lo) / 2;
        
        /* find maximum sum crossing to left */
        int leftMax = A[mid];
        int sum = 0;
        for(int i = mid; i >= lo; i--) {
            sum += A[i];
            if(sum > leftMax)
                leftMax = sum;
        }
        
        /* find maximum sum crossing to right */
        int rightMax = A[mid + 1];
        sum = 0;
        for(int i = mid + 1; i <= hi; i++) {
            sum += A[i];
            if(sum > rightMax)
                rightMax = sum;
        }
        
        /* Return the maximum of left side, right side OR across (mid, mid+1) */
        return max(leftMax + rightMax, max(maxSubArrayHelper(A, lo, mid), maxSubArrayHelper(A, mid + 1, hi)));
    }
};
