//============================================================================
// There are two sorted arrays A and B of size m and n respectively. Find the
// median of the two sorted arrays. The overall run time complexity should be
// O(log (m+n)).
//============================================================================

//T:log(k), k = m+n here
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sz = m + n;
        if((sz % 2) ==  1){
            return (double)findKth(A, 0, m, B, 0, n, sz/2 + 1); 
        }else{
            return (findKth(A, 0, m, B, 0, n, sz/2) + findKth(A, 0, m, B, 0, n, sz/2 + 1))/2.0;
        }      
    }
    
    int findKth(int A[], int s_a, int l_a, int B[], int s_b, int l_b, int k){
        if(l_a > l_b)
            return findKth(B, s_b, l_b, A, s_a, l_a, k);

        if(l_a == 0)
            return B[s_b + k - 1];
        if(k == 1)
            return min(A[s_a], B[s_b]);

        //log(k)
        int pos_a = min(k/2, l_a);
        int pos_b = k - pos_a;
        if(A[s_a + pos_a - 1] == B[s_b + pos_b - 1])
            return A[s_a + pos_a - 1];

        if(A[s_a + pos_a - 1] > B[s_b + pos_b - 1]){
            return findKth(A, s_a, l_a, B, s_b + pos_b, l_b - pos_b, k - pos_b);
        }else{
            return findKth(A, s_a + pos_a, l_a - pos_a, B, s_b, l_b, k - pos_a);
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = m + n;
        if(len%2==0){
            double a = kthsmallest(A,m,B,n,(m+n)/2);
            double b = kthsmallest(A,m,B,n,(m+n)/2+1);
            return a/2+b/2;
        }
        else{
            double a = kthsmallest(A,m,B,n,(m+n)/2+1);
            return a;
        }        
    }
    
    int kthsmallest(int* a,int lena, int* b, int lenb, int k){
        if(lena==0)
            return b[k-1];
        if(lenb==0)
            return a[k-1];

        int ma=lena/2; //ma mb is index now
        int mb=lenb/2;

    	if(ma + 1 + mb + 1<=k){ //ma+1 + mb+1 it the total length
            if(a[ma]>b[mb])
                //discard mb, biggest mb is (k-1)th sicne (ma + 1 - 1) + (mb +1) = k-1
                return kthsmallest(a,lena,b+mb+1,lenb-mb-1,k-mb-1); 
            else
                return kthsmallest(a+ma+1,lena-ma-1,b,lenb,k-ma-1);
    	}else{	
            if(a[ma]>b[mb])
                return kthsmallest(a,ma,b,lenb,k);
                //discard ma. smallest ma is (k+1)th since ma+ 1 + mb +1 >= k+1
            else
                return kthsmallest(a,lena,b,mb,k);
       }
    }
};

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays1(A, m, B, n);
        return findMedianSortedArrays2(A, m, B, n);
    }

    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = -1, m2 = -1;
        int s = (m + n) / 2;
        while (s >= 0) {
            int a = (i < m) ? A[i] : INT_MAX;
            int b = (j < n) ? B[j] : INT_MAX;
            m1 = m2;
            if (a < b) {
                m2 = a;
                i++;
            }else {
                m2 = b;
                j++;
            }
            s--;
        }
        if ((m + n) % 2 == 0)
            return (m1 + m2) / 2.0;
        return m2;
    };

    double findMedianSortedArrays2(int A[], int m, int B[], int n) {
        return findMedianHelper2(A, m, B, n, max(0, (m-n)/2), min(m-1, (m+n)/2));
    };

    double findMedianHelper2(const int A[], const int m, const int B[], const int n, const int l, const int r) {
        if (l > r)
            return findMedianHelper2(B, n, A, m, max(0, (n-m)/2), min(n-1, (m+n)/2));
        int i = (l+r)/2;
        int j = (m+n)/2-i;

        assert(i >= 0 && i <= m && j >= 0 && j <= n);
        int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
        int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
        int Ai = ((i == m) ? INT_MAX : A[i]);
        int Bj = ((j == n) ? INT_MAX : B[j]);

        if (Ai < Bj_1)
             return findMedianHelper2(A, m, B, n, i+1, r);
        if (Ai > Bj)
            return findMedianHelper2(A, m, B, n, l, i-1);

        if (((m+n) % 2) == 1)
            return A[i];
        return (max(Ai_1, Bj_1) + Ai) / 2.0;
    };
};
