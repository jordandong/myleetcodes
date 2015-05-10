/*
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

click to show more hints.
Hints:
1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
2. There are several ways to represent a graph. For example, the input prerequisites is a graph represented by a list of edges. Is this graph representation appropriate?
3. Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
4. Topological sort could also be done via BFS.

Hide Tags Depth-first Search Breadth-first Search Graph Topological Sort
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > g(numCourses, vector<int>()); //edge x->y
        vector<int> indgree(numCourses);//indgree for y
        stack<int> stk;
        int taken = 0;

        for (int i = 0; i < prerequisites.size(); i++) { //build graph
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            g[x].push_back(y);
            indgree[y]++;
        }
        
       for (int i = 0; i < numCourses; i++){
           if (indgree[i] == 0) { //take most dependent first
               stk.push(i);
               taken++;
           }
       }
       
       while (stk.size()) {
           int n = stk.top();
           stk.pop();
           for (int i = 0; i < g[n].size(); i++) {
               indgree[g[n][i]]--; //reduce the indgree after taking one course
               if (indgree[g[n][i]] == 0) {
                   stk.push(g[n][i]);
                   taken++;
               }
           }
       }
       return taken == numCourses;
    }
};
