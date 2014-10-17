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


class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n <= 0)
            return 0;
        
        int maxi = A[0], mini = A[0];
        int last_maxi, last_mini;
        int res = A[0];

        for (int i=1; i<n; i++) {
            last_maxi = maxi;
            last_mini = mini;
            maxi = max(max(last_maxi * A[i], last_mini * A[i]), A[i]);
            mini = min(min(last_maxi * A[i], last_mini * A[i]), A[i]);
            res = max(res, maxi);
        }
        return res;
    }
};
