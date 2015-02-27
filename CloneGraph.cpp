/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

Hide Tags Depth-first Search Breadth-first Search Graph
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        
        set<UndirectedGraphNode*> visited;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> old_new;
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        old_new[node] = new_node;
        cloneGraphHelper(node, new_node, old_new, visited);
        return new_node;
    }

    //DFS    
    void cloneGraphHelper(UndirectedGraphNode *node, UndirectedGraphNode *new_node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &old_new, set<UndirectedGraphNode*> &visited){
        
        if(!node || visited.find(node) != visited.end())
            return;
        
        visited.insert(node);
        int n_size = node->neighbors.size();
        for(int i =0; i<n_size; i++){
            auto got = old_new.find(node->neighbors[i]);
            if(got != old_new.end()){
                new_node->neighbors.push_back(got->second);
            }else{
                UndirectedGraphNode* tmp = new UndirectedGraphNode(node->neighbors[i]->label);
                new_node->neighbors.push_back(tmp);
                old_new[node->neighbors[i]] = tmp;
            }
            cloneGraphHelper(node->neighbors[i], new_node->neighbors[i], old_new, visited);
        }
    }
};
