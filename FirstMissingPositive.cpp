class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i=0;
        int j=0;
        while(i<n){
            if(A[i]<=n&&A[i]>0&&A[i]!=i+1&&A[A[i]-1]!=A[i])
                swap(A[i],A[A[i]-1]);
            else
                i++;
        }
        
        for (j=0;j<n;j++){
            if(A[j]!=j+1)
                return j+1;
        }
        
        return j+1;
        
    }
};
