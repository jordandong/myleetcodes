/*
An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.

The ith edge connects nodes edges[i][0] and edges[i][1] together.

Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.

Example 1:

Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
Output: [8,12,6,10,10,10]
Explanation: 
Here is a diagram of the given tree:
  0
 / \
1   2
   /|\
  3 4 5
We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
Note: 1 <= N <= 10000
*/

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> tree(N);
        vector<int> dis_sum(N, 0), child_cnt(N, 0);
        if (N == 1)
            return dis_sum;
        for (auto e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        unordered_set<int> v1, v2;
        countChild(0, v1, tree, dis_sum, child_cnt);
        updDis(0, v2, tree, dis_sum, child_cnt, N);
        return dis_sum;
    }

private:
    void countChild(int root, unordered_set<int>& v, vector<vector<int>>& tree, vector<int>& dis_sum, vector<int>& child_cnt) {
        v.insert(root);
        for (auto i : tree[root]) {
            if (v.count(i) == 0) {
                countChild(i, v, tree, dis_sum, child_cnt);
                child_cnt[root] += child_cnt[i]; //total child count under root
                dis_sum[root] += dis_sum[i] + child_cnt[i]; //total sum include root
            }
        }
        child_cnt[root] += 1; //includ root
    }

    void updDis(int root, unordered_set<int>& v, vector<vector<int>>& tree, vector<int>& dis_sum, vector<int>& child_cnt, int N) {
        v.insert(root);
        for (auto i : tree[root]) {
            if (v.count(i) == 0) {
                //When moving root from parent to its child i
                //child_cnt[i] nodes get 1 closer to new root, n - child_cnt[i] nodes get 1 futhur to new root.
                dis_sum[i] = dis_sum[root] - child_cnt[i] + (N - child_cnt[i]);
                updDis(i, v, tree, dis_sum, child_cnt, N);
            };
        }
    }
};
