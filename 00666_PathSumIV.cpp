/*
If the depth of a tree is smaller than 5, then this tree can be represented by a list of three-digits integers.

For each integer in this list:
The hundreds digit represents the depth D of this node, 1 <= D <= 4.
The tens digit represents the position P of this node in the level it belongs to, 1 <= P <= 8. The position is the same as that in a full binary tree.
The units digit represents the value V of this node, 0 <= V <= 9.
Given a list of ascending three-digits integers representing a binary with the depth smaller than 5. You need to return the sum of all paths from the root towards the leaves.

Example 1:
Input: [113, 215, 221]
Output: 12
Explanation: 
The tree that the list represents is:
    3
   / \
  5   1

The path sum is (3 + 5) + (3 + 1) = 12.
Example 2:
Input: [113, 221]
Output: 4
Explanation: 
The tree that the list represents is: 
    3
     \
      1

The path sum is (3 + 1) = 4.
*/

class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> mp(4, vector<int>(8, -1));
        for (auto e : nums) {
            int lv = e / 100 - 1;
            int idx = (e % 100) / 10 - 1;
            int v = e % 10;
            if (lv == 0)
                mp[lv][idx] = v;
            else
                mp[lv][idx] = mp[lv - 1][idx / 2] + v;
        }

        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 8; j++) {
                if (mp[i][j] == -1)
                    continue;
                if (i == 3 || (mp[i + 1][j * 2] == -1 &&  mp[i + 1][j * 2 + 1] == -1))
                    sum += mp[i][j];
            }
        }
        return sum;
    }
};
