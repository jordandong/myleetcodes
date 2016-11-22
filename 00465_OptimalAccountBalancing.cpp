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
    vector<vector<int>> data = {{0,1,10}, {2,0,5}};//2
    data = {{0,1,10}, {0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}};//1
    data = {{0,1,1},{2,3,2},{4,5,3},{6,7,4},{8,9,5},{10,11,6},{12,13,7},{14,15,2},{14,16,2},{14,17,2},{14,18,2}};//11
    cout<<s.minTransfers(data)<<endl;;
    return 0;
}
