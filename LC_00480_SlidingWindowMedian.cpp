/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3
[2,3], the median is (2 + 3) / 2 = 2.5

Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Your job is to output the median array for each window in the original array.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Median
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
Therefore, return the median sliding window as [1,-1,-1,3,5,6].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Hide Similar Problems (H) Find Median from Data Stream
*/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi; //internally it is balanced BST
        int N = nums.size();
        vector<double> res;
        for(int i = 0; i < N; i++){
            if(i - k >= 0){
                auto it = lo.lower_bound(nums[i - k]);//log(k)
                if(it != lo.end())
                    lo.erase(it);//log(k)
                else
                    hi.erase(hi.lower_bound(nums[i - k]));//log(k)
            }
            
            if(lo.size() <= hi.size()){
                if((lo.empty() && hi.empty()) || nums[i] <= *hi.begin()){
                    lo.insert(nums[i]);//log(k)
                }else{
                    hi.insert(nums[i]);//log(k)
                    lo.insert(*hi.begin());//log(k)
                    hi.erase(hi.begin());//log(k)
                }
            }else{
                if(nums[i] >= *lo.rbegin()){
                    hi.insert(nums[i]);//log(k)
                }else{
                    lo.insert(nums[i]);//log(k)
                    hi.insert(*lo.rbegin());//log(k)
                    lo.erase(lo.lower_bound(*lo.rbegin()));//log(k) + log(k)
                }
            }
            
            if(i >= k - 1) {
                if (lo.size() == hi.size())
                    res.push_back((*lo.rbegin() * 1.0 + *hi.begin())/2.0);
                else
                    res.push_back(*lo.rbegin() * 1.0);
            }
        }
        return res;
    }
};
