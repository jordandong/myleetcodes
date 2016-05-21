/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
You are given a 2D grid of values 0, 1 or 2, where:
Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):
    1 - 0 - 2 - 0 - 1
    |   |   |   |   |
    0 - 0 - 0 - 0 - 0
    |   |   |   |   |
    0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

Hide Tags Breadth-first Search
Hide Similar Problems (M) Walls and Gates (H) Best Meeting Point
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m,vector<int>(n,0));// using vector to store information about the total distance for each possible node.
        vector<vector<int>> newGrid = grid;// we dont want to change original matrix;
        int canAchieve = 0, minDist = INT_MAX;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));// current 1 position, we start BFS;
                    vector<vector<int>> dist(m,vector<int>(n,0));
                    //using dist to store distance information start from current building.
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(auto d : dirs){
                            int newX = cur.first+d.first, newY = cur.second+d.second;
                            if(newX < m && newX >= 0 && newY < n && newY >= 0 && newGrid[newX][newY] == canAchieve){
                                --newGrid[newX][newY];
                                dist[newX][newY] = dist[cur.first][cur.second] + 1;
                                total[newX][newY] += dist[newX][newY];
                                q.push(make_pair(newX, newY));
                            }
                        }
                    }
                    --canAchieve;//after each update, we change the node we can achieve by --canAchieve.
                }
            }
        }
        for(int i = 0; i < total.size(); ++i){
            for (int j = 0; j < total[0].size(); ++j) {
                if(total[i][j] && newGrid[i][j] == canAchieve)
                    minDist = min(minDist, total[i][j]);// insure all building can achieve this point!;
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
