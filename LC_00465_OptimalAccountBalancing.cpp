/*
A group of friends went on holiday and sometimes lent each other money.
For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride.
We can model each transaction as a tuple (x, y, z) which means person x gave person y $z.
Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.

Note:
A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.

Example 1:
Input:
[[0,1,10], [2,0,5]]
Output:
2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.

Example 2:
Input:
[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
Output:
1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
*/

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& t) {
        unordered_map<int, int> m;
        int r = 0, c = 0;
        for (auto &x: t) {
            m[x[0]] += x[2];
            m[x[1]] -= x[2];
        }
        vector<int> a;
        for (auto &x: m) {
            if (x.second)
                a.push_back(x.second);
        }
        if (a.empty())
            return 0;

        vector<int> dp(1 << a.size(), INT_MAX/2), sum_zero; //dp[i] means using balances represented by bits in i
        for (int i = 1; i < (1 << a.size()); i++) {
            int sum = 0, cnt = 0;
            for (int j = 0; j < a.size(); j++) {
                if ((i >> j) & 1) {//jth bit (jth balance) is used
                    sum += a[j];
                    cnt++;
                }
            }
            if (!sum) { //sum == 0
                dp[i] = cnt - 1; //cnt - 1 transaction could solve the balances, remove one balance one time, at most cnt - 1
                for (int pre : sum_zero) {
                    if ((i & pre) == pre) //current bits in i includes previous sum-zero bits
                        dp[i] = min(dp[i], dp[pre] + dp[i - pre]); //using the solution already found
                }
                sum_zero.push_back(i); //add sum zero bits
            }
        }
        return dp.back();
    }
};

class Solution {
public:
    int minTransfers(vector<vector<int>> transactions) {
        unordered_map<int, int> loan;
        list<int> rich, poor;
        for (auto &e : transactions) {
            loan[e[0]] += e[2];
            loan[e[1]] -= e[2];
        }
        for ( auto it = loan.begin(); it != loan.end(); ++it) {
            if (it->second > 0)
                rich.push_back(it->second);
            else if (it->second < 0)
                poor.push_back(-it->second);
        }
        return minTransfersHelper(rich, poor);
    }
    
    int minTransfersHelper (list<int> &rich, list<int> &poor) {
        int ans = INT_MAX;
        for (auto ri = rich.begin();  ri != rich.end(); ri++) {
            int r = *ri;
            if (r == 0)
                continue;
            for (auto pi = poor.begin(); pi != poor.end(); pi++) {
                int p = *pi;
                if (p == 0)
                    continue;
                if (r < p) {
                    *pi = p - r;
                    *ri = 0;
                } else if (r > p) {
                    *ri = r - p;
                    *pi = 0;
                } else {
                    *ri = 0;
                    *pi = 0;
                }
                ans = min(minTransfersHelper(rich, poor) + 1, ans);
                *ri = r;
                *pi = p;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    // your code goes here
    Solution s;
    vector<vector<int>> data = {{0,1,10}, {2,0,5}}; //2
    data = {{0,1,10}, {0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}}; //1
    data = {{0,1,1},{2,3,2},{4,5,3},{6,7,4},{8,9,5},{10,11,6},{12,13,7},{14,15,2},{14,16,2},{14,17,2},{14,18,2}};//11
    data = {{1,5,1}, {3, 5, 3}, {5, 2, 2}, {5, 4, 2}}; //3
    data = {{6,29,18},{1,22,84},{4,25,16},{7,22,16},{5,27,79},{7,27,60},{3,28,95},{4,20,95},{7,25,99},{1,29,25},{9,21,87},{4,26,39},{5,23,67},{6,22,68},{3,29,94},{8,24,66},{6,28,33},{9,28,85},{8,28,28},{3,21,25},{7,26,3},{3,22,89},{6,28,58},{6,28,45},{1,29,3},{7,21,95},{0,25,14},{8,27,37},{5,21,98},{9,23,57},{8,24,21},{8,25,78},{2,23,15},{3,24,50},{1,26,66},{6,21,38},{6,28,30},{8,29,49},{3,20,86},{4,22,91},{1,21,18},{1,26,22},{5,25,75},{5,28,48},{2,26,83},{3,28,3},{2,27,76},{7,22,73},{8,27,97},{2,26,49},{0,20,83},{7,23,47},{9,29,94},{2,27,43},{5,25,50},{7,29,76},{1,20,26},{9,28,77},{1,29,63},{9,26,55},{1,25,17},{3,28,37}};//17(15)
    data = {{8,23,20},{3,24,78},{4,20,37},{0,29,66},{2,29,2},{0,20,23},{0,22,65},{5,24,34},{0,27,6},{6,21,16},{1,26,2},{4,21,73},{8,27,64},{6,27,39},{5,25,15},{5,23,28},{8,25,53},{6,27,98},{0,25,92},{5,28,91},{8,21,75},{1,25,39},{1,22,55},{1,25,14},{4,26,70},{6,29,30},{6,26,11},{1,28,68},{1,26,13},{7,21,4},{3,29,77},{0,26,93},{7,20,39},{5,22,91},{9,27,80},{1,23,71},{6,29,27},{8,26,95},{8,29,24},{7,25,70},{1,29,17},{9,29,98},{6,22,26},{1,24,74},{0,25,33},{0,24,68},{8,25,91},{8,23,36},{1,29,25},{8,27,82},{4,24,14}};//18(16)
    data = {{0,3,2},{1,4,3},{2,3,2},{2,4,2}};//3
    cout<<s.minTransfers(data)<<endl;;
    return 0;
}
