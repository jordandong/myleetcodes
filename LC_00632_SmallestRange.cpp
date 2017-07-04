/*
You have k lists of sorted integers in ascending order.
Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]

Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Note:
1. The given list may contain duplicates, so ascending order means >= here.
2. 1 <= k <= 3500
3. -10^5 <= value of elements <= 10^5.
*/


class Solution {
public:
    typedef vector<int>::iterator vi;

    struct comp {
        bool operator()(pair<vi, vi> p1, pair<vi, vi> p2) {
            return *p1.first > *p2.first;
        }
    };
            
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pair<vi, vi>, vector<pair<vi, vi>>, comp> pq;
        for (auto &row : nums) {
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.push({row.begin(), row.end()});
        }
        
        vector<int> ans = {lo, hi};
        while (true) {
            auto p = pq.top();
            pq.pop();
            
            lo = *p.first;
            if (hi - lo < ans[1] - ans[0]) //no equal since b-a < d-c or a < c if b-a == d-c.
                ans = {lo, hi};

            ++p.first; //no more
            if (p.first == p.second)
                break;
            hi = max(hi, *p.first);//update max
            pq.push(p);
        }
        return ans;
    }
};


class Solution {
public:     
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> m; //{value, idx}
        unordered_map<int, int> c; //{idx, ref_cnt}
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++)
                m.push_back({nums[i][j], i});
        }
            
        sort(m.begin(), m.end(), 
             [](pair<int, int> &a, pair<int, int> &b){
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first < b.first;
             });

        int dist = INT_MAX;
        for (int i = 0, j = 0; j < m.size(); j++) {
            c[m[j].second]++;
            if (c.size() == nums.size()) {
                while (c[m[i].second] > 1)
                    c[m[i++].second]--;
                
                if (m[j].first - m[i].first < dist) {
                    dist = m[j].first - m[i].first;
                    ans = {m[i].first, m[j].first};
                }
            }
        }
        return ans;
    }
};
