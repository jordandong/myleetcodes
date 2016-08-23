/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)

Hide Tags Array Hash Table Two Pointers
*/

//T: O(N^2)  S: O(N^2)
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int sz = nums.size();
        vector<vector<int> > res;
        unordered_map<int, vector<pair<int, int> > > data;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz; i++)
            for(int j = i+1; j < sz; j++)
                data[nums[i]+nums[j]].push_back(make_pair(i,j));
                
        for(int i = 0; i < sz - 3; i++){
            if(i > 0 && nums[i]==nums[i-1])//reduce dup for the 1st element
                continue;   
            for(int j = i+1; j < sz - 2; j++){
                if(j > i+1 && nums[j]==nums[j-1])//reduce dup for the 2nd element
                    continue;   
                int left = target - nums[i] - nums[j];
                if(data.find(left) == data.end())
                    continue;
                vector<pair<int, int> > &v = data[left];
                bool added = false;
                for(int k = 0; k < v.size(); k++){
                    if(v[k].first <= j)//reduce the dup across four elements
                        continue;
                    if(!added || nums[v[k].first] != res.back()[2]){ //reduce dup for the last two elements
                        vector<int> sol;
                        sol.push_back(nums[i]);
                        sol.push_back(nums[j]);
                        sol.push_back(nums[v[k].first]);
                        sol.push_back(nums[v[k].second]);
                        res.push_back(sol);
                        added = true;
                    }
                }
            }
        }
        return res;
    }
};

//T: O(N^2 * (log(N) + N))  S: O(N^2)
struct TwoSum{
public:
    int index1;
    int index2;
    int value;
    TwoSum(int idx1, int idx2, int v) :
        index1(idx1), index2(idx2), value(v) {}

};

struct increaing {
    bool operator() (TwoSum ts1, TwoSum ts2) {
        if (ts1.value == ts2.value){
            if (ts1.index1 == ts2.index1)
            	return (ts1.index2 < ts2.index2);
            else
                return (ts1.index1 < ts2.index1);
        }
        else
            return (ts1.value < ts2.value);
    }
};

class Solution {
public:
    int find_start_index(vector<TwoSum>& twoSums, int begin, int end, int val){
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (twoSums[mid].value >= val)
            	end = mid - 1;
            else
            	begin = mid + 1;
        }
        return end + 1;
    };

    int find_end_index(vector<TwoSum>& twoSums, int begin, int end, int val){
        while (begin <= end) {
            int mid = begin + (end - begin) / 2;
            if (twoSums[mid].value <= val)
            	begin = mid + 1;
            else
            	end = mid - 1;
        }
        return begin - 1;
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // calculate sum for every two elements and sort
        vector<TwoSum> twoSums;
        for (size_t i = 0; i < num.size(); i++){
            for (size_t j = i + 1; j < num.size(); j++) {
                twoSums.push_back(TwoSum(i, j, num[i] + num[j]));
            }
        }
        sort(twoSums.begin(), twoSums.end(), increaing());

        vector<vector<int> > result;
        for (size_t i = 0; i < twoSums.size(); i++){
            size_t begin, end;
            int val = target - twoSums[i].value;

            begin = find_start_index(twoSums, i + 1, twoSums.size() - 1, val);
            end = find_end_index(twoSums, i + 1, twoSums.size() - 1, val);

            for (size_t j = begin; j <= end; j++) {
                if (twoSums[j].index1 == twoSums[i].index1)
                    continue;
                if (twoSums[j].index2 == twoSums[i].index1)
                    continue;
                if (twoSums[j].index1 == twoSums[i].index2)
                    continue;
                if (twoSums[j].index2 == twoSums[i].index2)
                    continue;

                vector<int> tmp;
                tmp.push_back(num[ twoSums[i].index1]);
                tmp.push_back(num[ twoSums[i].index2]);
                tmp.push_back(num[ twoSums[j].index1]);
                tmp.push_back(num[ twoSums[j].index2]);
                sort(tmp.begin(), tmp.end());

                if (find(result.begin(), result.end(), tmp) == result.end())
                    result.push_back(tmp);
            }
        }
        return result;
    };
};

//brute force, T: O(N^3)  S: O(1)
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(num.size() < 4)
            return res;
            
        int size = num.size();
        sort(num.begin(),num.end());
        for(int j = 0;j < size - 3; j++){
            if(j > 0 && num[j] == num[j-1])
                continue;
            for(int i = j+1; i < size-2; i++){
            	if(i > j+1 && num[i] == num[i-1])
            	    continue;
            	int begin =i+1;
            	int end = size-1;
            	while(begin < end){
            	    if (num[begin] == num[begin-1] && begin > i+1){
            	    	begin++;
            	    	continue;
            	    }
            	    if (num[end] == num[end+1] && end < size-1){
            	    	end--;
            	    	continue;
            	    }
            	    int sum =num[j]+num[i]+num[begin]+num[end];
            	    if(sum==target){
            	    	vector<int> tmp;
            	    	tmp.push_back(num[j]);
            	    	tmp.push_back(num[i]);
            	    	tmp.push_back(num[begin]);
            	    	tmp.push_back(num[end]);
            	    	res.push_back(tmp);
            	    	begin++;
            	    	end--;
            	    }else if(sum > target){
            	    	end--;
            	    }else{
            	    	begin++;
            	    }
		}
            }
	}
	return res;
    }
};
