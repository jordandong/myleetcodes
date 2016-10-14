/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
        0
        |
        1
       / \
      2   3
return [1]

Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:
How many MHTs can a graph have at most? Two

Note:
(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

Credits:
Special thanks to @peisi for adding this problem and creating all test cases.

Hide Tags Breadth-first Search Graph
*/

class Solution {
public:
    struct node {
        unordered_set<int> neighbors;
    };

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1)
            return {0};

        unordered_map<int, node> nodes;
        for (const auto& edge : edges) {
            nodes[edge.first].neighbors.insert(edge.second);
            nodes[edge.second].neighbors.insert(edge.first);
        }

        vector<int> leaves;
        //find all the leaves which has only one connection
        for (int i = 0; i < n; ++i)
            if (nodes[i].neighbors.size() == 1)
                leaves.push_back(i);

        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int i : leaves) {
                int j = *(nodes[i].neighbors.begin()); //get parent
                nodes[j].neighbors.erase(i); //remove child from parent
                if (nodes[j].neighbors.size() == 1) //if parent becomes leaf
                    newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves; //the last set of leaves are the results
    }
};
