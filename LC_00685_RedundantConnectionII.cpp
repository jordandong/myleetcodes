/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node,
plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added.
The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes.
If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3

Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3

Note:
1. The size of the input 2D-array will be between 3 and 1000.
2. Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> parent(2001, 0), candA, candB;
        for (auto &e : edges) {
            if (parent[e[1]] == 0) {
                parent[e[1]] = e[0]; 
            } else {
                candA = {parent[e[1]], e[1]};
                candB = e;
                e[1] = 0; //remove second dup parent edge
            }
        } 

        for (auto e : edges) {
            parent[e[0]] = e[0];
            parent[e[1]] = e[1];
        }
        
        for (auto e : edges) {
            if (e[1] == 0) //skip the removed edge
                continue;
            int f = unionFind(parent, e[0]);
            int t = unionFind(parent, e[1]);
            if  (f == t) { //there is a cycle
                if (candA.empty()) //no dup parent case
                    return e;
                return candA; //the first dup parent edge
            } else {
                parent[t] = f;
            }
        }
        return candB; //no cycle, the second dup parent edge
    }
    
private:
    int unionFind(vector<int> &p, int val) {
        while (p[val] != val) {
            val = p[val];
        }
        return val;
    }
};
