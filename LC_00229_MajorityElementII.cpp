/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:
How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 0, b = 0;
        int cnta = 0, cntb = 0;
        for (auto e : nums) {
            if (cnta == 0 && cntb == 0) {
                cnta = 1;
                a = e;
                continue;
            }
            
            if (cnta == 0 && b != e) {
                cnta = 1;
                a = e;
                continue;
            }
            
            if (cntb == 0 && a != e) {
                cntb = 1;
                b = e;
                continue;
            }
            
            if (e == a) {
                cnta++;
            } else if (e == b) {
                cntb++;
            } else {
                cnta--;
                cntb--;
            }
        }
        
        int sa=0, sb=0;
        vector<int> res;
        for (auto e : nums) {
            if (cnta > 0 && a == e)
                sa++;
            if (cntb > 0 && b == e)
                sb++;
        }
        if (sa * 3 > nums.size())
            res.push_back(a);
        if (sb * 3 > nums.size())
            res.push_back(b);
        return res;
    }
};
