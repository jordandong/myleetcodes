/*
TBD
Given a sorted array of integers and integer values a, b and c, apply a function of the form f(x) = ax^2+bx+c to each element x in the array.

The returned array should be sorted.

Example:

Given x = [-4 , -2 , 2 , 4] , a=1 , b=3 , c=5, output should be [3, 9, 15, 33].
Given x = [-4 , -2 , 2 , 4] , a=-1 , b=3 , c=5, output should be [-23, -5, 1, 7].

Expected time complexity : O(n);
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size());
        if (nums.size() == 0)
            return res;
        int i = 0, j = nums.size() - 1;
        if (a > 0) {
            int k = nums.size() - 1;
            while (i <= j) {
                if (transform(nums[i], a, b, c) > transform(nums[j], a, b, c)) {
                    res[k--] = transform(nums[i], a, b, c);
                    i++;
                } else {
                    res[k--] = transform(nums[j], a, b, c);
                    j--;
                }
            }
        } else {
            int k = 0;
            while (i <= j) {
                if (transform(nums[i], a, b, c) < transform(nums[j], a, b, c)) {
                    res[k++] = transform(nums[i], a, b, c);
                    i++;
                } else {
                    res[k++] = transform(nums[j], a, b, c);
                    j--;
                }
            }
        }
        return res;
    }
        
    int transform(int num, int a, int b, int c) {
        return a * num * num + b * num + c;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4 , -2 , 2 , 4};
    vector<int> res = sol.sortTransformedArray(nums, 1, 3, 5);
    for (auto e : res) {
        cout<<e<<" ";
    }
    cout<<endl;
    res = sol.sortTransformedArray(nums, -1, 3, 5);
    for (auto e : res) {
        cout<<e<<" ";
    }
    cout<<endl;


    return 0;
}

3 9 15 33 
-23 -5 1 7
