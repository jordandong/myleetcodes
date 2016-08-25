/*
A 2d grid map of m rows and n columns is initially filled with water.
We may perform an addLand operation which turns the water at position (row, col) into a land.
Given a list of positions to operate, count the number of islands after each addLand operation.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example:
Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
1 0 0
0 0 0   Number of islands = 1
0 0 0

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
1 1 0
0 0 0   Number of islands = 1
0 0 0

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
1 1 0
0 0 1   Number of islands = 2
0 0 0

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
1 1 0
0 0 1   Number of islands = 3
0 1 0

We return the result as an array: [1, 1, 2, 3]
*/

class UnionFind2D {
public:
    UnionFind2D(int m, int n) {
        for (int i = 0; i < m * n; i++)
            ids.push_back(-1);
        for (int i = 0; i < m * n; i++)
            szs.push_back(1);
        M = m, N = n, cnt = 0;
    }
    int index(int x, int y) {
        return x * N + y;
    }
    int size(void) {
        return cnt;
    }
    int id(int x, int y) {
        if (x >= 0 && x < M && y >= 0 && y < N)
            return ids[index(x, y)];
        return -1;
    }
    int add(int x, int y) {
        int idx = index(x, y);
        ids[idx] = idx;
        szs[idx] = 1;
        cnt++;
        return idx;
    }
    int root(int i) {
        for (; i != ids[i]; i = ids[i])
            ids[i] = ids[ids[i]];
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p), j = root(q);
        if (szs[i] > szs[j])
            swap(i, j);
        ids[i] = j;
        szs[j] += szs[i];
        cnt--;
    }
private:
    vector<int> ids, szs;
    int M, N, cnt;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        UnionFind2D islands(m, n);
        vector<pair<int, int>> dirs = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
        vector<int> ans;
        for (auto& pos : positions) {
            int x = pos.first, y = pos.second;
            int p = islands.add(x, y);
            for (auto& d : dirs) {
                int q = islands.id(x + d.first, y + d.second);
                if (q >= 0 && !islands.find(p, q))
                    islands.unite(p, q);
            }
            ans.push_back(islands.size());
        }
        return ans;
    }
};

// Time:  O(klog*k) ~= O(k), k is the length of the positions
// Space: O(k)
// Using unordered
// Using unordered_map.
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> numbers;
        int number = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        unordered_map<int, int> set;
        for (const auto& position : positions) {
            const auto& node = make_pair(position.first, position.second);
            set[node_id(node, n)] = node_id(node, n);
            ++number;

            for (const auto& d : directions) {
                const auto& neighbor = make_pair(position.first + d.first,
                                                 position.second + d.second);
                if (neighbor.first >= 0 && neighbor.first < m &&
                    neighbor.second >= 0 && neighbor.second < n &&
                    set.find(node_id(neighbor, n)) != set.end()) {
                    if (find_set(node_id(node, n), &set) != 
                        find_set(node_id(neighbor, n), &set)) {
                        // Merge different islands, amortised time: O(log*k) ~= O(1)
                        union_set(&set, node_id(node, n), node_id(neighbor, n));
                        --number;
                    }
                }
            }
            numbers.emplace_back(number);
        }

        return numbers;
    }

    int node_id(const pair<int, int>& node, const int n) {
        return node.first * n + node.second;
    }

    int find_set(int x, unordered_map<int, int> *set) {
       if ((*set)[x] != x) {
           (*set)[x] = find_set((*set)[x], set);  // path compression.
       }
       return (*set)[x];
    }

    void union_set(unordered_map<int, int> *set, const int x, const int y) {
        int x_root = find_set(x, set), y_root = find_set(y, set);
        (*set)[min(x_root, y_root)] = max(x_root, y_root);
    }
};

// Time:  O(klog*k) ~= O(k), k is the length of the positions
// Space: O(m * n)
// Using vector.
class Solution2 {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> numbers;
        int number = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        vector<int> set(m * n, -1);
        for (const auto& position : positions) {
            const auto& node = make_pair(position.first, position.second);
            set[node_id(node, n)] = node_id(node, n);
            ++number;

            for (const auto& d : directions) {
                const auto& neighbor = make_pair(position.first + d.first,
                                                 position.second + d.second);
                if (neighbor.first >= 0 && neighbor.first < m &&
                    neighbor.second >= 0 && neighbor.second < n &&
                    set[node_id(neighbor, n)] != -1) {
                    if (find_set(node_id(node, n), &set) != 
                        find_set(node_id(neighbor, n), &set)) {
                        // Merge different islands, amortised time: O(log*k) ~= O(1)
                        union_set(&set, node_id(node, n), node_id(neighbor, n));
                        --number;
                    }
                }
            }
            numbers.emplace_back(number);
        }

        return numbers;
    }

    int node_id(const pair<int, int>& node, const int m) {
        return node.first * m + node.second;
    }

    int find_set(int x, vector<int> *set) {
        int parent = x;
        while ((*set)[parent] != parent) {
            parent = (*set)[parent];
        }
        while ((*set)[x] != x) {
            int tmp = (*set)[x];
            (*set)[x] = parent;
            x = tmp;
        }
        return parent;
    }

    void union_set(vector<int> *set, const int x, const int y) {
        int x_root = find_set(x, set), y_root = find_set(y, set);
        (*set)[min(x_root, y_root)] = max(x_root, y_root);
    }
};

