//============================================================================
// Remove Duplicates from Sorted Array II
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
// For example,
// Given sorted array A = [1,1,1,2,2,3],
//
// Your function should return length = 5, and A is now [1,1,2,2,3].
//============================================================================

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        unordered_map<int, int> mp;
        int i=0;
        int j=0;
        while(j<n){
            if(mp.find(A[j])==mp.end()){
                mp[A[j]]=1;
                A[i++]=A[j++];
            }else if(mp[A[j]]>=2){
                j++;
            }else{
                mp[A[j]]++;
                A[i++]=A[j++];
            }
        }
        return i;
    }
};


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<3)
            return n;
        else{
            int flag = 0;
            int pos = 1;
            for(int i=1;i<n;i++){
                if(A[i-1]!=A[i]){
                    flag=0;
                    if(flag<=1){
                        A[pos] = A[i];
                        pos++;
                    }
                }
                else{
                    flag++;
                    if(flag<=1){
                        A[pos] = A[i];
                        pos++;
                    }
                }
            }
            return pos;
        }
    }
};



class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2)
        	return n;
        int i = 1, j = 0;
        bool first = true;
        while (i < n) {
            if (A[i] != A[j]) {
                A[++j] = A[i++];
                first = true;
            }
            else {
                if (first) {
                    A[++j] = A[i++];
                    first = false;
                }
                else {
                    i++;
                }
            }
        }
        return j + 1;
    }
};

int main() {
    return 0;
}
