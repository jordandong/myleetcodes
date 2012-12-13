//============================================================================
// Given an array S of n integers, are there elements a, b, c in S such that
// a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
//
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4},
//
// A solution set is:
// (-1, 0, 1)
// (-1, -1, 2)
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int N = num.size();
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        for (int k = 0; k < N-2; k++) {
            int i = k+1;
            int j = N-1;
            while (i < j) {
                int sum = num[i] + num[j] + num[k];
                if (sum > 0)
                	j--;
                else if (sum < 0)
                	i++;
                else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[j]);
                    triplet.push_back(num[k]);
                    sort(triplet.begin(), triplet.end());
                    if (find(result.begin(), result.end(), triplet) == result.end()) {
                        result.push_back(triplet);
                    }
                    i++;
                    j--;
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}


class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int> > res;
			if(num.size()<3)
				return res;
			int size = num.size();
			sort(num.begin(),num.end());

			for(int i=0;i<size-2;i++){
				if(num[i]>0)
					break;
				if (i > 0 && num[i] == num[i-1])  
					continue;

				int begin =i+1;
				int end = size-1;
				while(begin < end){
					int sum = num[i]+num[begin]+num[end]; 
					if(sum==0){
						if (num[begin] == num[begin-1] && begin > i+1){  
							begin = begin + 1;  
							continue;  
						}
						vector<int> tmp;
						tmp.push_back(num[i]);
						tmp.push_back(num[begin]);
						tmp.push_back(num[end]);
						res.push_back(tmp);
						begin++;
						end--;
					}
					else if (sum > 0)   
					{  
						end = end - 1;  
						if (num[end] == num[end+1]){  
							end = end - 1;  
						}  
					}  
					else  
					{  
						begin = begin + 1;  
						if (num[begin] == num[begin-1])  {  
							begin = begin + 1;  
						}  
					} 
				}
			}
			return res;
		}
};
