/*
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input: 
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
Example 2:
Input: 
flowers: [1,2,3]
k: 1
Output: -1
Note:
The given array will be in the range [1, 20000].

*/

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> bloom; //internally Binary Tree
        for (int i = 0; i < flowers.size(); i++) {
            int p = flowers[i];
            auto it = bloom.insert(p).first;
            auto it2 = it;
            //today and previous day
            if (it2 != bloom.begin() && (p - *(--it2) == k + 1))
                return i + 1;
            //today and future day
            it2 = it;
            if ((++it2) != bloom.end() && (*it2 - p == k + 1))
                return i + 1; 
        }
        return -1;
        
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for (int i = 0; i < flowers.size(); i++)
            days[flowers[i] - 1] = i + 1; //day[x] = y means position x blooming at day y
        int l_pos = 0, r_pos = k + 1, res = INT_MAX;
        for (int i = 0; r_pos < days.size(); i++) {
            if (days[i] < days[l_pos] || days[i] <= days[r_pos]) {   
                if(i == r_pos)
                    res = min(res, max(days[l_pos], days[r_pos]));
                //means between l_pos and i blooming after i, so able to skip 
                l_pos = i;
                r_pos = i + k + 1;
            }
        }
        return (res == INT_MAX) ? -1 : res;        
    }
};
