/*
There are N network nodes, labelled 1 to N.
Given times, a list of travel times as directed edges times[i] = (u, v, w),
where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal?
If it is impossible, return -1.

Note:
1. N will be in the range [1, 100].
2. K will be in the range [1, N].
3. The length of times will be in the range [1, 6000].
4. All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<pair<int, int>> g[N + 1];
        vector<int> d(N + 1, 1 + N * 100);
        vector<bool> in_q(N + 1, false);
        
        for (auto &t : times)
            g[t[0]].push_back(make_pair(t[1], t[2]));
        
        d[K] = 0;
        
        queue<int> q;
        q.push(K);
        while (q.size()) {
            int u = q.front();
            q.pop();
            in_q[u] = false;
            for (auto e : g[u]) {
                int v = e.first;
                int w = e.second;
                int new_d = d[u] + w;
                if (new_d < d[v]) {
                    d[v] = new_d;
                    if (!in_q[v]) {
                        in_q[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        int mx = 0;
        for (int i = 1; i <= N; ++i) {
            if (d[i] >= 1 + N * 100)
                return -1;
            mx = max(mx, d[i]);
        }
        return mx;
    }
};
