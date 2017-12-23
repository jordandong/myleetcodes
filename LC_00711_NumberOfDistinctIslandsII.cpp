/*
Given a non-empty 2D array grid of 0’s and 1’s, an island is a group of 1‘s (representing land) connected 4-directionally (horizontal or vertical.)
You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands.
An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).

Example 1:
11000
10000
00001
00011
Given the above grid map, return 1.

Notice that:
11
1
and
 1
11
are considered same island shapes.
Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.

Example 2:
11100
10001
01001
01110
Given the above grid map, return 2.

Here are the two distinct islands:
111
1
and
1
1

Notice that:
111
1
and
1
111
are considered same island shapes.
Because if we flip the first array in the up/down direction, then they have the same shapes.

Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        std::unordered_set<int> signatures;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c]) {
                    vector<pair<int, int>> pts;
                    visit(grid, m, n, r, c, pts);
                    int hash = compute_hash(pts);
                    signatures.insert(hash);
                }
            }
        }
        return signatures.size();
    }
    
private:
    int compute_hash(vector<pair<int, int>>& pts) {
        int n = pts.size();
        int hash = 0;
        // int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
        std::unordered_map<int, int> stats1, stats2;
        
        for (int i = 0; i < n; ++i) {
            const auto& pt1 = pts[i];
            // xmin = std::min(xmin, pt1.first);
            // ymin = std::min(ymin, pt1.second);
            // xmax = std::max(xmax, pt1.first);
            // ymax = std::max(ymax, pt1.second);
            stats1[pt1.first]++;
            stats2[pt1.second]++;
            for (int j = i + 1; j < n; ++j) {
                const auto& pt2 = pts[j];
                int delta_x = pt1.first - pt2.first;
                int delta_y = pt1.second - pt2.second;
                if (delta_x == 0 || delta_y == 0) {
                    hash += 19 * (delta_x * delta_x + delta_y * delta_y);
                } else {
                    hash += 31 * (delta_x * delta_x + delta_y * delta_y);
                } 
            }
        }
        
        for (auto& kv : stats1) {
            hash += 73 * kv.second * kv.second;
        }
        for (auto& kv : stats2) {
            hash += 73 * kv.second * kv.second;
        }
        
        // int delta_x = xmax - xmin, delta_y = ymax - ymin;
        int delta_x = stats1.size(), delta_y = stats2.size();
        hash += 193 * (delta_x * delta_x + delta_y * delta_y) + 97 * delta_x * delta_y;
        return hash;
    }
    
    void visit(vector<vector<int>>& grid, int m, int n, int r, int c,
               vector<pair<int, int>>& pts) {
        bool outOfBound = (r < 0 || r >= m || c < 0 || c >= n);
        if (outOfBound || grid[r][c] == 0) return;
        
        grid[r][c] = 0;
        pts.emplace_back(r, c);
        visit(grid, m, n, r - 1, c, pts);
        visit(grid, m, n, r + 1, c, pts);
        visit(grid, m, n, r, c - 1, pts);
        visit(grid, m, n, r, c + 1, pts);
    }    
};

int main() {
    Solution sol;
    vector<vector<int>> data;
    //data = {{1,1,0,0,0},{1,0,0,0,0},{0,0,0,0,1},{0,0,0,1,1}};
    data = {{1,1,1,0,0},{1,0,0,0,1},{0,1,0,0,1},{0,1,1,1,0}};
    cout<<sol.numDistinctIslands2(data)<<endl;
    return 0;
}
