/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to check whether these edges make up a valid tree.

For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: 
“a tree is an undirected graph in which any two vertices are connected by exactly one path.
In other words, any connected graph without simple cycles is a tree.”
Note:
1. you can assume that no duplicate edges will appear in edges.
2. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together inedges.
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> neighbors(n);
        for (auto e : edges) {
            neighbors[e.first].push_back(e.second);
            neighbors[e.second].push_back(e.first);
        }
        vector<bool> visited(n, false);
        if (hasCycle(neighbors, 0, -1, visited))
            return false;
        for (bool v : visited)
            if (!v)
                return false; 
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited) {
        if (visited[kid])
            return true;
        visited[kid] = true;
        for (auto neigh : neighbors[kid])
            if (neigh != parent && hasCycle(neighbors, neigh, kid, visited))
                return true;
        return false;
    }
};


class Solution {
public:
    struct node {
        int parent = -1;
        vector<int>neighbors;
    };

    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        } else if (n == 1) {
            return true;
        }

        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.push_back(edge.second);
            nodes[edge.second].neighbors.push_back(edge.first);
        }

        if (nodes.size() != n) {
            return false;
        }

        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            visited.emplace(i);
            for (const auto& node : nodes[i].neighbors) {
                if (node != nodes[i].parent) {
                    if (visited.find(node) != visited.end()) {
                        return false;
                    } else {
                        visited.emplace(node);
                        nodes[node].parent = i;
                        q.push(node);
                    }
                }
            }
        }
        return visited.size() == n;
    }
};
