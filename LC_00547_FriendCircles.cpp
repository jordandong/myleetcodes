/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
And you have to output the total number of friend circles among all the students.

Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:
The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.

Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:
The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

Note:
1. N is in range [1,200].
2. M[i][i] = 1 for all students.
3. If M[i][j] = 1, then M[j][i] = 1.

Hide Tags Depth-first Search Union Find
*/

//DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        for (int i = 0; i < M.size(); i++) {
            if (M[i][i] == 1) { //unvisited
                res++;
                findCircleNumHelper(M, i);
            }
        }
        return res;
    }
private:
    void findCircleNumHelper(vector<vector<int>>& M, int i) {
        M[i][i]++;//visited
        for (int j = 0; j < M.size(); j++) {
            if (i != j && M[i][j] == M[j][j])//only check unvisited node
                findCircleNumHelper(M, j);
                
        }
    }
};

//Union and Find
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        int res = N;
        vector<int> parent(N, -1); //small index is root
        for (int i = 0; i < N; ++i)
            parent[i] = i;
        for (int r = 0; r < N; ++r) {
            for (int c = r + 1; c < N; ++c) {
                if (M[r][c] == 1) {
                    int rParent = find(parent, r);
                    int cParent = find(parent, c);
                    if (rParent != cParent) {
                        parent[cParent] = rParent;//r; //union
                        --res;
                    }
                }
            }
        }
        return res;
    }
private:
    int find (vector<int> &parent, int index) {
        while (parent[index] != index)
            index = parent[index];
        return index;
    }
};
