/*
We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

Example:
Input: 
routes = [[1, 2, 7], [3, 6, 7]]
S = 1
T = 6
Output: 2
Explanation: 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Note:

1 <= routes.length <= 500.
1 <= routes[i].length <= 500.
0 <= routes[i][j] < 10 ^ 6.
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        unordered_map<int, set<int>> mp;//<stop, bus#>
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop: routes[i])
                mp[stop].insert(i);
        }
        
        int ans = 1, idx = 0;
        queue<int> q[2];
        q[idx % 2].push(S);
        while (!q[idx % 2].empty()) {
            int cstop = q[idx % 2].front();
            q[idx % 2].pop();
            for (int bus : mp[cstop]) { //bus at cstop
                for (auto nstop : routes[bus]) { //take this bus and get next potential stops
                    if (T == nstop)
                        return ans;
                    if (nstop != cstop) {
                        q[(idx + 1) % 2].push(nstop);
                        mp[nstop].erase(bus);//from cstop to nstop on this bus, delete it in mp to avoid take the same bus back 
                    }
                }
            }
            mp[cstop].clear(); //delete current stop
            if (q[idx % 2].empty()) {
                idx++;
                ++ans;
            }
        }
        return -1;
    }
};
