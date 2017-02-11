
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty() || start.empty() || destination.empty())
            return -1;
        int row = maze.size(), col = maze[0].size();
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        distance[start[0]][start[1]] = 0;
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        while (!q.empty()) {
            int cur_x = q.front().first, cur_y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int next_x = cur_x, next_y = cur_y;
                int move = 0;
                while (next_x + directions[i].first >= 0 && next_x + directions[i].first < row &&
                       next_y + directions[i].second >= 0 && next_y + directions[i].second < col &&
                       maze[next_x + directions[i].first][next_y + directions[i].second] == 0) {
                    next_x += directions[i].first;
                    next_y += directions[i].second;
                    move++;
                }
                if (distance[next_x][next_y] > distance[cur_x][cur_y] + move){
                    distance[next_x][next_y] = distance[cur_x][cur_y] + move;
                    q.push({next_x, next_y});
                }
            }
        }
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};

int main() {
    Solution s;
    vector<vector<int>> maze = {{0,0,0,0,0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0}};
    vector<int> start = {1, 4};
    vector<int> destination = {5, 4};
    cout<<s.shortestDistance(maze, start, destination)<<endl;
    return 0;
}
