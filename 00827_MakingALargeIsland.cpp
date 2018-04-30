/*
In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 1.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 1.
 

Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.
*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(); 
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int area_id = 2, cnt = 0, res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt = 0;
                    assignAreaId(grid, i, j, area_id, cnt, mp);
                    res = max(res, mp[area_id++]);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> po;
                    int tmp_res = 0;
                    if (i - 1 >= 0 && grid[i - 1][j] > 1)
                        po[grid[i - 1][j]] = mp[grid[i - 1][j]];
                    if (j - 1 >= 0 && grid[i][j - 1] > 1)
                        po[grid[i][j - 1]] = mp[grid[i][j - 1]];
                    if (i + 1 < m && grid[i + 1][j] > 1)
                        po[grid[i + 1][j]] = mp[grid[i + 1][j]];
                    if (j + 1 < n && grid[i][j + 1] > 1)
                        po[grid[i][j + 1]] = mp[grid[i][j + 1]];
                    for (auto &p : po)
                        tmp_res += p.second;
                    res = max(res, 1 + tmp_res);
                }
            }
        }
        return res;
    }

private:
    void assignAreaId(vector<vector<int>>& grid, int i, int j, int area_id, int &cnt, unordered_map<int, int> &mp) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return;
        cnt++;
        mp[area_id] = max(mp[area_id], cnt);
        grid[i][j] = area_id;
        
        assignAreaId(grid, i + 1, j, area_id, cnt, mp);
        assignAreaId(grid, i - 1, j, area_id, cnt, mp);
        assignAreaId(grid, i, j + 1, area_id, cnt, mp);
        assignAreaId(grid, i, j - 1, area_id, cnt, mp);        
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(); 
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        int area_id = 2, res = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    mp[area_id] = assignAreaId(grid, i, j, area_id);
                    res = max(res, mp[area_id++]);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> po;
                    int tmp_res = 0;
                    if (i - 1 >= 0 && grid[i - 1][j] > 1)
                        po[grid[i - 1][j]] = mp[grid[i - 1][j]];
                    if (j - 1 >= 0 && grid[i][j - 1] > 1)
                        po[grid[i][j - 1]] = mp[grid[i][j - 1]];
                    if (i + 1 < m && grid[i + 1][j] > 1)
                        po[grid[i + 1][j]] = mp[grid[i + 1][j]];
                    if (j + 1 < n && grid[i][j + 1] > 1)
                        po[grid[i][j + 1]] = mp[grid[i][j + 1]];
                    for (auto &p : po)
                        tmp_res += p.second;
                    res = max(res, 1 + tmp_res);
                }
            }
        }
        return res;
    }

private:
    int assignAreaId(vector<vector<int>>& grid, int i, int j, int area_id) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
            return 0;
        grid[i][j] = area_id;
        int ans = 0;
        ans += assignAreaId(grid, i + 1, j, area_id);
        ans += assignAreaId(grid, i - 1, j, area_id);
        ans += assignAreaId(grid, i, j + 1, area_id);
        ans += assignAreaId(grid, i, j - 1, area_id);   
        return ans + 1;
    }
};
