
#include <iostream>
#include <tuple>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
class Solution {
	public:
    int minTransfers(vector<tuple<int, int, int>> transactions) {
	unordered_map<int, int> loan;
	int x, y, z;
	vector<int> rich, poor;
        for (auto &e : transactions) {
		tie(x, y, z) = e;			
		loan[x] += z;
		loan[y] -= z;
	}
	for ( auto it = loan.begin(); it != loan.end(); ++it) {
		if (it->second > 0) {
			rich.push_back(it->second);
		} else if (it->second < 0) {
			poor.push_back(-it->second);
		}
	}
        return solve(rich, poor);
    }

    int solve(vector<int> rich, vector<int> poor) {
            int rlen = rich.size(), plen = poor.size(); 
            if (min(rlen, plen) <= 1)
                return max(rlen, plen);
            int ans = INT_MAX;
            for (int ri = 0;  ri < rlen; ri++) {
                for (int pi = 0; pi < plen; pi++) {
                    vector<int> nrich = rich;
		    nrich.erase(nrich.begin() + ri);
                    vector<int> npoor = poor;
		    npoor.erase(npoor.begin() + pi);

                    if (rich[ri] < poor[pi]) {
                        npoor.push_back(poor[pi] - rich[ri]);
		    } else if (rich[ri] > poor[pi]) {
                        nrich.push_back(rich[ri] - poor[pi]);
		    }
                    ans = min(solve(nrich, npoor) + 1, ans);
		}
	    }
            return ans;
    }
};

int main() {
	// your code goes here
	Solution s;
	//vector<tuple<int, int, int>> data = {make_tuple(0,1,10), make_tuple(2,0,5)};
	vector<tuple<int, int, int>> data = {make_tuple(0,1,10), make_tuple(0,1,10), make_tuple(1,0,1), make_tuple(1,2,5), make_tuple(2,0,5)};
	cout<<s.minTransfers(data)<<endl;;
	return 0;
}
