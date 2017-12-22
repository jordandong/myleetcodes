/*
A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

The world is modeled as a 2-D array of cells, where 0 represents uninfected cells, and 1 represents cells contaminated with the virus.
A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited.
Each day, you can install walls around only one region -- the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night.
There will never be a tie.

Can you save the day? If so, what is the number of walls required?
If not, and the world becomes fully infected, return the number of walls used.

Example 1:
Input: grid = 
[[0,1,0,0,0,0,0,1],
 [0,1,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,1],
 [0,0,0,0,0,0,0,0]]
Output: 10
Explanation:
There are 2 contaminated regions.
On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
[[0,1,0,0,0,0,1,1],
 [0,1,0,0,0,0,1,1],
 [0,0,0,0,0,0,1,1],
 [0,0,0,0,0,0,0,1]]
On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

Example 2:
Input: grid = 
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output: 4
Explanation: Even though there is only one cell saved, there are 4 walls built.
Notice that walls are only built on the shared boundary of two different cells.

Example 3:
Input: grid = 
[[1,1,1,0,0,0,0,0,0],
 [1,0,1,0,1,1,1,1,1],
 [1,1,1,0,0,0,0,0,0]]
Output: 13
Explanation: The region on the left only builds two new walls.

Note:
1. The number of rows and columns of grid will each be in the range [1, 50].
2. Each grid[i][j] will be either 0 or 1.
3. Throughout the described process, there is always a contiguous viral region that will infect strictly more uncontaminated squares in the next round.
*/

class Solution {
private:
    struct Region {
        unordered_set<int*> infected, potential;
        int p_walls = 0;
    };

    vector<Region> findRegions(vector<vector<int>>& grid, int &max_border) {
        vector<Region> regions;
        max_border = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    Region r;
                    dfs(grid, i, j, r);
                    regions.push_back(r);
                    if (max_border < r.potential.size())
                        max_border= r.potential.size();
                }
            }
        }
        return regions;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, Region &r) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] < 0)
            return;
        
        if (grid[i][j]) {
            grid[i][j] = -1;
            r.infected.insert(&grid[i][j]);
            dfs(grid, i + 1, j, r);
            dfs(grid, i, j + 1, r);
            dfs(grid, i - 1, j, r);
            dfs(grid, i, j - 1, r);
        } else {
            r.potential.insert(&grid[i][j]);
            ++r.p_walls;
        }
    };

public:
    int containVirus(vector<vector<int>>& grid) {                          
        int walls = 0, max_border = 0;
        while (true) {
            // find all infected regions
            auto regions = findRegions(grid, max_border);
            if (regions.size() == 0)
                return walls; // no more infection
            
            // update all regions
            for (auto &r : regions) {
                if (r.potential.size() != max_border) { //being infected
                    for (auto &cell : r.infected)
                        *cell = 1;
                    for (auto &cell : r.potential)
                        *cell = 1;
                } else {
                    walls += r.p_walls; // quarantined
                }
            }
        }
    }
};
