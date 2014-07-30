//============================================================================
// Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
// Note:
// You may assume that A has enough space to hold additional elements from B.
// The number of elements initialized in A and B are m and n respectively.
//============================================================================

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = m+n;
        while(m>=1&&n>=1){
            if(A[m-1]>B[n-1]){
                A[len-1] = A[m-1];
                m--;
                len--;
            }else{
                A[len-1] = B[n-1];
                n--;
                len--;
            }
        }
        //if(m>0&&n==0);
        while(m==0&&n>0){
            A[len-1]=B[n-1];
            len--;
            n--;
        }
    }
};

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while (i >= 0 && j >= 0){
            if (A[i] >= B[j])
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
        while (i >= 0)
            A[k--] = A[i--];
        while (j >= 0)
            A[k--] = B[j--];
    }
};
