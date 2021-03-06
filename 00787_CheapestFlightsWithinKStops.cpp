/*
There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.

Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:
        0
   100     500
1     100      2

The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:
        0
   100     500
1     100      2

The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
Note:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.
*/

//DP
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e9;
        K++;
        vector<vector<int>> ans(n, vector<int>(K + 1, INF));
        ans[src][0] = 0;
        for(int i = 1; i <= K; i++) {
            for(int j = 0; j < n; j++)
                ans[j][i] = ans[j][i - 1];
            for(const vector<int>& f: flights)
                ans[f[1]][i] = min(ans[f[1]][i], ans[f[0]][i - 1] + f[2]);
        }
        if(ans[dst][K] == INF)
            return -1;
        return ans[dst][K];
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e9;
        vector<vector<int>> ans(2, vector<int>(n, INF));
        ans[0][src] = 0;
        for(int i = 0; i <= K; i++) {
            ans[(i + 1) % 2] = ans[i % 2];
            for(const vector<int>& f: flights)
                ans[(i + 1) % 2][f[1]] = min(ans[(i + 1) % 2][f[1]], ans[i % 2][f[0]] + f[2]);
        }
        if(ans[(K + 1) % 2][dst] == INF)
            return -1;
        return ans[(K + 1) % 2][dst];
    }
};

//Dijkstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> m (n, INT_MAX);
        m[src] = 0;
        
        unordered_map<int,vector<pair<int,int> > > es;
        for(int i = 0; i < flights.size(); ++i)
            es[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        
        auto comp = [&](const auto &p1, const auto &p2)->bool{
            return m[p1.first] > m[p2.first] || (m[p1.first] == m[p2.first] && p1.first > p2.first);
        };
        
        unordered_set<int> visited; 
        priority_queue<pair<int, int>, vector<pair<int,int> >, decltype(comp)> q(comp);  
        q.push({src,0}); 
        visited.insert(src);
        
        while(!q.empty()){
            auto f = q.top();
            q.pop();
                    
            if((f.second) > K)
                continue;
            
            for(auto &e : es[f.first]){
                if(m[e.first] > m[f.first] + e.second){
                    m[e.first] = m[(f.first)] + e.second;
                    q.push({e.first, f.second + 1});
                }
            }
        }
        return m[dst] == INT_MAX ? -1 : m[dst];
    }
};
