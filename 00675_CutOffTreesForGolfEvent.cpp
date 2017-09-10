/*
You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:

0 represents the obstacle can't be reached.
1 represents the ground can be walked through.
The place with number bigger than 1 represents a tree can be walked through, and this positive number represents the tree's height.
You are asked to cut off all the trees in this forest in the order of tree's height - always cut off the tree with lowest height first. And after cutting, the original place has the tree will become a grass (value 1).

You will start from the point (0, 0) and you should output the minimum steps you need to walk to cut off all the trees. If you can't cut off all the trees, output -1 in that situation.

You are guaranteed that no two trees have the same height and there is at least one tree needs to be cut off.

Example 1:
Input: 
[
 [1,2,3],
 [0,0,4],
 [7,6,5]
]
Output: 6
Example 2:
Input: 
[
 [1,2,3],
 [0,0,0],
 [7,6,5]
]
Output: -1
Example 3:
Input: 
[
 [2,3,4],
 [0,0,5],
 [8,7,6]
]
Output: 6
Explanation: You started from the point (0,0) and you can cut off the tree in (0,0) directly without walking.
Hint: size of the given matrix will not exceed 50x50.
*/

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<vector<int>, vector<vector<int>>, TreeComparator> trees;
        int m = forest.size(), n = forest[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1)
                    trees.push({ i, j, forest[i][j] });
            }
        }

        int total = 0;
        int i = 0, j = 0, i1 = 0, j1 = 0;
        while (!trees.empty()) {
            vector<int> tree = trees.top();
            trees.pop();
            i1 = tree[0];
            j1 = tree[1];
            int dist2next = bfsDist(forest, i, j, i1, j1);
            if (dist2next == -1)
                return -1;
            total += dist2next;
            i = i1, j = j1;
        }
        return total;
    }

private:
    struct TreeComparator {
        bool operator()(vector<int> a, vector<int> b) {
            return a[2] > b[2];
        }
    };

    int bfsDist(vector<vector<int>> forest, int i0, int j0, int i1, int j1) {
        if (i0 == i1 && j0 == j1)
            return 0;
        int m = forest.size(), n = forest[0].size();
        vector<pair<int, int>> delta = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({i0, j0});
        forest[i0][j0] = -forest[i0][j0];
        int dist = 0;
        while (!q.empty()) {
            dist++;
            for (int k = q.size(); k > 0; k--) {
                pair<int, int> p = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int i = p.first + delta[d].first, j = p.second + delta[d].second;
                    if (i == i1 && j == j1)
                        return dist;
                    if (i < 0 || m <= i || j < 0 || n <= j || forest[i][j] <= 0)
                        continue;
                    forest[i][j] = -forest[i][j];
                    q.push({i, j});
                }
            }
        }
        return -1;
    }
};
