/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

Hide Tags Backtracking Math
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        if(n <= 0 || k <= 0)
            return "";
        long long fac = 1;
        string p(n, '0');
        string res = "";
        for(int i = 1; i <= n; i++){
            fac *= i;
            p[i - 1] = ('0' + i);//index start from 0
        };
        
        // change range of k from (1,n) to (0, n-1) to adapt the index in p
        k--;
        for (int i = n; i >= 1; i--){
            // divide fact first
            fac /= i;
            res.push_back(p[k/fac]); //d0 = k / (n-1)!, also k2 = k % (n-1)!, d1 = k2 % (n-2)!...
            p.erase(k/fac, 1); //remove the used num
            k %= fac; //left k
        };
        return res;
    }
};

//Cannot pass TLE
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n <= 0 || k <= 0)
            return "";
        string p(n, '0');
        for(int i = 1; i <= n; i++)
            p[i-1] = ('0' + i);
        while(k-- > 0)
           getNextPermutation(p);
        return p;
    }
    
    void getNextPermutation(string &p) {
        int sz = p.length();
        
        int i = sz - 2;
        while(i >=0 && p[i] >= p[i + 1])
            i--;
        if(i == -1){
            reverse(p.begin(), p.end());
            return;
        }
        
        int j = sz - 1;
        while(j > i && p[j] <= p[i])
            j--;
        
        swap(p[i], p[j]);
        reverse(p.begin()+ i + 1, p.end());
    }
};
