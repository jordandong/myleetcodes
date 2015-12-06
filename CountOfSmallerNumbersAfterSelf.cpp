/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:
Given nums = [5, 2, 6, 1]
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

Hide Tags Divide and Conquer Binary Indexed Tree Segment Tree Binary Search Tree
*/

//T : O(NlogN),  S : O(N)
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, 0);
        if(N == 0)
            return res;
        countOfSmallerHelper(nums, 0, N - 1, res);//Merge and Sort
        return res;
    }
    
    vector<int> countOfSmallerHelper(vector<int> &A, int s, int e, vector<int> &res) {
        vector<int> rtn;
        if(s == e){
            rtn.push_back(s);
            return rtn;
        }
        
        vector<int> l, r;
        int mid = s + (e - s)/2;
        l = countOfSmallerHelper(A, s, mid, res);
        r = countOfSmallerHelper(A, mid + 1, e, res);
        int i = 0, j = 0;
        while(i < l.size() && j < r.size()){
            if(A[l[i]] > A[r[j]]){
                rtn.push_back(l[i]);//sort the value from big to small, but store the index
                res[l[i]] += r.size() - j; //record the conuts of smaller values in the right part
                i++;
            }else{
                rtn.push_back(r[j]);
                j++;
            }
        }
        while(j < r.size()){
            rtn.push_back(r[j]);
            j++;
        }
        while(i < l.size()){
            rtn.push_back(l[i]);
            res[l[i]] += r.size() - j;//record the conuts of smaller values in the right part
            i++;
        }
        return rtn;
    }
};
