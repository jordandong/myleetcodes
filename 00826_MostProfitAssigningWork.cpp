/*
We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 

Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

Example 1:

Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100 
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
Notes:

1 <= difficulty.length = profit.length <= 10000
1 <= worker.length <= 10000
difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
*/

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int N = profit.size(), res = 0, i = 0, maxp = 0;
        for (int j = 0; j < N; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int & ability: worker) {
            while (i < N && ability >= jobs[i].first) 
                maxp = max(jobs[i++].second, maxp);
            res += maxp;
        }
        return res; 
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> m;
        for (int i = 0; i < difficulty.size(); i++)
            m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
        int mx = 0, res = 0;
        for (auto &p : m)
            mx = p.second = max(p.second, mx);
        for (int w : worker) {
            auto it = m.upper_bound(w);
            if (it != m.begin()) {
                res += prev(it)->second;
                //it--;
                //res += it->second;
            }
        }
        return res;
    }
};
