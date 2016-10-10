/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
1. The order of returned grid coordinates does not matter.
2. Both m and n are less than 150.

Example:
Given the following 5x5 matrix:
  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic
Return:
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

Hide Tags Depth-first Search Breadth-first Search
*/

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0)
            return {};
        int N = matrix[0].size();
        if (N == 0)
            return {};
            
        vector<pair<int, int> > res;
        set<int> pac, alt;
        for (int i = 0; i < M; i++) {
            DFS(i, 0, -1, matrix, pac);
            DFS(i, N - 1, -1, matrix, alt);
        }
            
        for (int j = 0; j < N; j++) {
            DFS(0, j, -1, matrix, pac);
            DFS(M - 1, j, -1, matrix, alt);
        }
        
        for (auto &e : pac) {
            if(alt.count(e))
                res.push_back(make_pair(e >> 16, e & 0xffff));
        }
            
        return res;
    }
    
    void DFS(int x, int y, int last_val, vector<vector<int>> &m, set<int> &visited) {
        if (x < 0 || x >= m.size() || y < 0 || y >= m[0].size() || visited.count((x<<16) | y) || m[x][y] < last_val)
            return;
        visited.insert((x<<16) | y);
        DFS(x + 1, y, m[x][y], m, visited);
        DFS(x - 1, y, m[x][y], m, visited);
        DFS(x, y + 1, m[x][y], m, visited);
        DFS(x, y - 1, m[x][y], m, visited);
    }
};
