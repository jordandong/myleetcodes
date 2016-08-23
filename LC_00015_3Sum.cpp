/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
  (-1, 0, 1)
  (-1, -1, 2)
Hide Tags Array Two Pointers
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	vector<vector<int> > res;
	int sz = num.size();
	if(sz < 3)
		return res;
	
	sort(num.begin(),num.end());
	for(int i = 0; i < sz - 2; i++){
            if(num[i] > 0)
                break;
            if(i > 0 && num[i] == num[i-1])  
                continue;
           
            int s = i + 1;
            int e = sz - 1;
            while(s < e){
                if(s > i + 1 && num[s] == num[s - 1]){  
                    s++;  
                    continue;  
                }
                if(e < sz - 1 && num[e] == num[e + 1]){  
                    e--;  
		    continue;
                }
	
		int sum = num[i] + num[s] + num[e]; 
		if(sum == 0){
		    vector<int> tmp;
		    tmp.push_back(num[i]);
		    tmp.push_back(num[s]);
		    tmp.push_back(num[e]);
		    res.push_back(tmp);
		    s++;
		    e--;
		}else if(sum > 0){  
		    e--;  
		}else{
		    s++;
		}
            }
	}
	return res;
    }
};
