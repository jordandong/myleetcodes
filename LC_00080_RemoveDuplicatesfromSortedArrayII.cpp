/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

Hide Tags Array Two Pointers
*/

//T:O(N) S:O(1)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 3)
            return n;

        int tail = 2;
        int cur = 2;
        while(cur < n){
            if(A[cur] == A[tail - 1] && A[cur] == A[tail - 2])
                cur++;
            else
               A[tail++] = A[cur++];    
        }
        return tail;
    }
};

//T:O(N) S:O(1)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
            return n;
        int k = 0, i = 0;
        int found = 0;
        while(i < n){
            if(A[i] == A[k]){
                if(found == 1)//found the second one, copy it
                    A[++k] = A[i];
                i++;
                found++;
            }else{
                A[++k] = A[i++];//copy cur i to the tail
                found = 1;
            }
        }
        return k + 1;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
            return n;
        int dupCnt = 1;
        int pos = 1;
        for(int i = 1; i < n; i++){
            if(A[i-1] != A[i]){
                dupCnt = 1;
                A[pos++] = A[i];
            }else{
                dupCnt++;
                if(dupCnt <= 2)
                    A[pos++] = A[i];
            }
        }
        return pos;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2)
        	return n;
        int i = 1, j = 0;
        bool first = true;
        while (i < n) {
            if (A[i] != A[j]) {
                A[++j] = A[i++];
                first = true;
            }else {
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

//T:O(N) S:O(N)
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        while(j < n){
            if(mp.find(A[j]) == mp.end()){
                mp[A[j]] = 1;
                A[i++] = A[j++];
            }else if(mp[A[j]] >= 2){
                j++;
            }else{
                mp[A[j]]++;
                A[i++] = A[j++];
            }
        }
        return i;
    }
};
