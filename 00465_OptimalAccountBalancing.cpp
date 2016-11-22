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
    vector<vector<int>> data = {{0,1,10}, {2,0,5}};
    data = {{0,1,10}, {0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}};
    cout<<s.minTransfers(data)<<endl;;
    return 0;
}
