/*
 *Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 *For example, given the array [2,3,-2,4],
 *the contiguous subarray [2,3] has the largest product = 6.
 */
 
class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxi = 1, mini = 1;
        int res  = INT_MIN;

        for (int i=0;i<n;i++) {
            int maxi_copy = max(maxi,1);
            if (A[i] > 0) {
                maxi = maxi_copy*A[i];
                mini *= A[i];
            } else {
                maxi = mini*A[i];
                mini = maxi_copy*A[i];
            }
            res = max(res,maxi);
        }
        return res;
    }
};
