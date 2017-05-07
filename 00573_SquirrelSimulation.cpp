/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

Example 1:
Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12
Explanation:

Note:
All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.
Discuss
*/

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        if (nuts.size() == 0)
            return -1;
        int mi = 0;
        int mi_dist = abs(nuts[0][0] - squirrel[0]) +
                      abs(nuts[0][1] - squirrel[1]) - 
                      abs(nuts[0][0] - tree[0]) - 
                      abs(nuts[0][1] - tree[1]);
        for (auto e : nuts) {
            int s2n = abs(e[0] - squirrel[0]) + abs(e[1] - squirrel[1]);
            int t2n = abs(e[0] - tree[0]) + abs(e[1] - tree[1]);
            if  (s2n - t2n <= mi_dist)
                mi_dist = s2n - t2n;
            mi += (t2n * 2);
        }
        mi += mi_dist;
        return mi;
    }
};
