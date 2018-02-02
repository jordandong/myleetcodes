/*
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.

Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.

Return the smallest possible value of D.

Example:
Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000

Note:
1. stations.length will be an integer in range [10, 2000].
2. stations[i] will be an integer in range [0, 10^8].
3. K will be an integer in range [1, 10^6].
4. Answers within 10^-6 of the true value will be accepted as correct.
*/

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int N = stations.size();
        double l = 0, r = stations[N - 1] - stations[0];
        while (l + 1e-6 < r) {
            double mid = l + (r - l) / 2;
            int cnt = 0;
            for (int i = 0; i < N - 1; ++i)
                cnt += ceil((stations[i + 1] - stations[i]) / mid) - 1;
            if (cnt > K)
                l = mid; //increase the dis
            else
                r = mid;
        }
        return r;
    }
};

class Comp {
public:
    bool operator() (pair<double, int> a, pair<double, int> b) {
        return (a.first/a.second) < (b.first/b.second);
    }
};

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        int N = stations.size(), alloc_k_sum = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, Comp> q;
        for (int i = 0; i < N - 1; i++) {
            double dis = stations[i + 1] - stations[i];
            int alloc_k = dis / (stations[N - 1] - stations[0]) * K; //allocate k as many as possible first
            q.push({dis, 1 + alloc_k});
            alloc_k_sum += alloc_k;
        }
        K -= alloc_k_sum; //remain K
        while (K > 0) {
            pair<double, int> cur = q.top(); //sort by distance
            q.pop();
            cur.second += 1;
            K--;
            q.push(cur);
        }
        return q.top().first / q.top().second;
    }
};
