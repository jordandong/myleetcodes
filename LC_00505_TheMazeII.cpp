/*
There is a ball in a maze with empty spaces and walls.
The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall.
When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination.
The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).
If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array.
1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls.
The start and destination coordinates are represented by row and column indexes.

Example 1
Input 1: a maze represented by a 2D array
0 0 1 0 b
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 h

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: 12
Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Example 2
Input 1: a maze represented by a 2D array
0 0 1 0 b
0 0 0 0 0
0 0 0 1 0
1 1 h 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: -1
Explanation: There is no way for the ball to stop at the destination.

Note:
1. There is only one ball and one destination in the maze.
2. Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
3. The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
4. The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

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

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Solution {
private:
    void shortestDistanceHelper(vector<vector<int>>& maze, vector<vector<int>> &distance, vector<int> cur, vector<int> &destination){
        if (cur[0] == destination[0] && cur[1] == destination[1])
            return;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int next_x = cur[0], next_y = cur[1];
            int move = 0;
            while (next_x + directions[i].first >= 0 &&
                   next_x + directions[i].first < maze.size() &&
                   next_y + directions[i].second >= 0 &&
                   next_y + directions[i].second < maze[0].size() &&
                   maze[next_x + directions[i].first][next_y + directions[i].second] == 0) {
                next_x += directions[i].first;
                next_y += directions[i].second;
                move++;
            }
            if (distance[next_x][next_y] > distance[cur[0]][cur[1]] + move) {
                distance[next_x][next_y] = distance[cur[0]][cur[1]] + move;
                shortestDistanceHelper(maze, distance, {next_x, next_y}, destination);
            }
        }
    }
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty() || start.empty() || destination.empty())
            return -1;
        int row = maze.size(), col = maze[0].size();
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        distance[start[0]][start[1]] = 0;
        shortestDistanceHelper(maze, distance, start, destination);
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
