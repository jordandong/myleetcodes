/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

//recursion
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int res = 0;
        int M = grid.size();
        if(M == 0)
            return res;
        int N = grid[0].size();
        if(N == 0)
            return res;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == '1'){
                    res++;
                    numIslandsHelper(i, j, grid);
                }
            }
        }
        return res;
    }
  
    void numIslandsHelper(int i, int j, vector<vector<char> > &grid) {
        if (grid[i][j] != '1') {
            return;
        }
        grid[i][j] = 'x';
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, -0}};
        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (0 <= x && x < grid.size() &&
                0 <= y && y < grid[0].size() &&
                grid[x][y] == '1') {
                numIslandsHelper(x, y, grid);
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int res = 0;
        int M = grid.size();
        if(M == 0)
            return res;
        int N = grid[0].size();
        if(N == 0)
            return res;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == '1'){
                    res++;
                    numIslandsHelper(i, j, grid);
                }
            }
        }
        return res;
    }
  
    void numIslandsHelper(int i, int j, vector<vector<char> > &grid) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
            return;
        grid[i][j] = 'x';
        numIslandsHelper(i + 1, j, grid);
        numIslandsHelper(i - 1, j, grid);
        numIslandsHelper(i, j + 1, grid);
        numIslandsHelper(i, j - 1, grid);
    }
};

//non recursion
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int res = 0;
        int M = grid.size();
        if(M == 0)
            return res;
        int N = grid[0].size();
        if(N == 0)
            return res;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == '1'){
                    res++;
                    numIslandsHelper(i, j, grid);
                }
            }
        }
        return res;
    }
  
    void numIslandsHelper(int i, int j, vector<vector<char> > &grid) {
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        grid[i][j] = 'x';
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, -0}};
        while (q.size()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (auto d : dir) {
                int x = i + d[0];
                int y = j + d[1];
                if (0 <= x && x < grid.size() &&
                    0 <= y && y < grid[0].size() &&
                    grid[x][y] == '1') {
                    grid[x][y] = 'x';
                    q.push(make_pair(x, y));
                }
            }
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        int res = 0;
        int M = grid.size();
        if(M == 0)
            return res;
        int N = grid[0].size();
        if(N == 0)
            return res;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == '1'){
                    res++;
                    numIslandsHelper(i, j, grid);
                }
            }
        }
        return res;
    }
  
    void numIslandsHelper(int i, int j, vector<vector<char> > &grid) {
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        grid[i][j] = 'x';
        while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i + 1 < grid.size() && grid[i + 1][j] == '1'){
                grid[i + 1][j] = 'x';
                q.push(make_pair(i + 1, j));
            }
            if(i - 1 >= 0 && grid[i - 1][j] == '1'){
                grid[i - 1][j] = 'x';
                q.push(make_pair(i - 1, j));
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == '1'){
                grid[i][j + 1] = 'x';
                q.push(make_pair(i, j + 1));
            }
            if(j - 1 >= 0 && grid[i][j - 1] == '1'){
                grid[i][j - 1] = 'x';
                q.push(make_pair(i, j - 1));
            }
        }
    }
};
