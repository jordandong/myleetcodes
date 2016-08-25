/*
Numbers can be regarded as product of its factors.
For example,
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
1. Each combination's factors must be sorted ascending,for example: The factors of 2 and 6 is [2, 6], not [6, 2].
2. You may assume that n is always positive.
3. Factors should be greater than 1 and less than n.

Examples: 
input: 1
output: 
[]

input: 37
output: 
[]

input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]

input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> factors;
        getResult(n, &result, &factors);
        return result;
    }

    void getResult(const int n, vector<vector<int>> *result, vector<int> *factors) {
        for (int i = factors->empty() ? 2 : factors->back(); i <= n / i; ++i) {
            if (n % i == 0) {
                factors->emplace_back(i);
                factors->emplace_back(n / i);
                result->emplace_back(*factors);
                factors->pop_back();
                getResult(n / i, result, factors);
                factors->pop_back();
            }
        }
    }
};


class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> results;
        vector<int> result;
        getFactorsRecur(n, results, result, 0);
        return results;
    }
    
    void getFactorsRecur(int n, vector<vector<int>> &results, vector<int> result, int last) {
        for(int i = 2; i < n; i++) {
            if(n / i >= i && i >= last && n % i == 0) {
                result.push_back(i);
                result.push_back(n / i);
                results.push_back(result);
                result.pop_back();
                getFactorsRecur(n / i, results, result, i);
                result.pop_back();
            }
        }
    }
};

int main() {
	Solution s;
	vector<vector<int>> res = s.getFactors(32);
	for (auto e : res) {
	    for (auto i : e) {
	        cout<<i<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}

2 16 
2 2 8 
2 2 2 4 
2 2 2 2 2 
2 4 4 
4 8 
