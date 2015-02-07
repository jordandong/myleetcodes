/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Hide Tags Array Hash Table
*/

//T:O(n), S:O(n)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> mp;
        vector<int> res(2,-1);
        for(int i=0; i < numbers.size();i++)
            mp[numbers[i]] = i+1; //duplicated value keep the lagestest index
        
        for(int i = 0; i < numbers.size(); i++){
            if(mp.find(target-numbers[i]) != mp.end()){
                int index = mp[target-numbers[i]];
                if(index != i+1){ //avoid found itself
                    res[0]=min(index, i+1);
                    res[1]=max(index, i+1);
                    break;
                }
            }
        }
        return res;
    }
};

//T: O(nlogn)  S:O(n) 
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int sz = numbers.size();
        int lo = 0;
        int hi = sz - 1;
        vector<int> res;
        vector<pair<int, int> > data;
        while(lo++ < sz)
            data.push_back(make_pair(numbers[lo-1], lo));
        sort(data.begin(), data.end(), cmp);
        
        lo = 0;
        while(lo < hi){
            int sum = data[lo].first + data[hi].first;
            if(sum < target)
                lo++;
            else if(sum > target)
                hi--;
            else
                break;
        }
        
        res.push_back(data[lo].second);
        res.push_back(data[hi].second);
        if(data[lo].second > data[hi].second)
            reverse(res.begin(), res.end());
        return res;
    }
};
