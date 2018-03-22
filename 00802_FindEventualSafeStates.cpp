/*
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:

graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
*/

class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<bool> circle(graph.size(), false);
        vector<bool> safe(graph.size(), false);
        for (int  i = 0; i < graph.size(); i++) {
            vector<bool> vis(graph.size(), false);
            if (eventualSafeNodesHelper(graph, i, vis, circle, safe))
                res.push_back(i);
        }
        return res;
    }

private:
    bool eventualSafeNodesHelper(vector<vector<int>>& graph, int node, 
                                 vector<bool> &vis, vector<bool> &circle, vector<bool> &safe) {
        if (circle[node] || vis[node])
            return false;
        if (safe[node])
            return true;
        vis[node] = true;
        for (int i = 0; i < graph[node].size(); i++) {
            if (eventualSafeNodesHelper(graph, graph[node][i], vis, circle, safe) == false) {
                circle[node] = true;
                return false;
            }
        }
        vis[node] = false;
        safe[node] = true;
        return true;
    }
};

class Solution {

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        set<int> circle, safe;
        for (int  i = 0; i < graph.size(); i++) {
            set<int> vis;
            if (eventualSafeNodesHelper(graph, i, vis, circle, safe))
                res.push_back(i);
        }
        return res;
    }

private:
    bool eventualSafeNodesHelper(vector<vector<int>>& graph, int node,
                                 set<int> &vis, set<int> &circle, set<int> &safe) {
        if (circle.find(node) != circle.end() || vis.find(node) != vis.end())
            return false;
        if (safe.find(node) != safe.end())
            return true;
        vis.insert(node);
        for (int i = 0; i < graph[node].size(); i++) {
            if (eventualSafeNodesHelper(graph, graph[node][i], vis, circle, safe) == false) {
                circle.insert(node);
                return false;
            }
        }
        vis.erase(node);
        safe.insert(node);
        return true;
    }
};
