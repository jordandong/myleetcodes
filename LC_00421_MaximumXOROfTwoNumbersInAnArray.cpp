/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
Could you do this in O(n) runtime?

Example:
Input: [3, 10, 5, 25, 2, 8]
Output: 28
Explanation: The maximum result is 5 ^ 25 = 28.

Hide Tags Bit Manipulation Trie
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        if (!nums.size())
            return 0;
        uint x = 0, m = 0, w = -1;
        for (auto& n : nums) {
            m |= n;
            w &= n;
        }
        m &= ~w;
        unordered_set<uint> s;
        for (uint i = 1 << 31; i; i >>= 1) {
            if (!(m & i))
                continue;
            uint t = x | i;
            for (auto& n : nums) {
                if (s.count((n & t) ^ t)) { //if XOR results is already found
                    x = t;
                    break;
                } else {
                    s.insert(n & t);
                }
            }
            s.clear();
        }
        return x;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        unordered_set<int> st;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            st.clear();
            for (int num : nums)
                st.insert(num & mask); // reserve Left bits and ignore Right bits

            int ans = max | (1 << i); // in each iteration, there are pair(s) whoes Left bits can XOR to max
            for (int prefix : st) {
                if (st.find(ans ^ prefix) != st.end()) {
                    max = ans;
                    break;
                }
            }
        }
        return max;
    }
};
