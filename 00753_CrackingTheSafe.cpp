/*
There is a box protected by a password. The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

You can keep inputting the password, the password will automatically be matched against the last n digits entered.

For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

Example 1:
Input: n = 1, k = 2
Output: "01"
Note: "10" will be accepted too.

Example 2:
Input: n = 2, k = 2
Output: "00110"
Note: "01100", "10011", "11001" will be accepted too.

Note:
n will be in the range [1, 4].
k will be in the range [1, 10].
k^n will be at most 4096.
*/

class Solution {
public:
    string crackSafe(int n, int k) {
        int total = pow(k, n);
        string sol(n, '0');
        set<string> v;
        v.insert(sol);
        crackSafeDFS(sol, total, v, n, k);
        return sol;
    }
    
private:
    bool crackSafeDFS(string &sol, int total, set<string> &v, int n, int k) {
        if (v.size() == total)
            return true;
        string prev = sol.substr(sol.length() - n + 1);
        for (int i = 0; i < k; i++) {
            string next = prev + to_string(i);
            if (v.find(next) == v.end()) {
                v.insert(next);
                sol.push_back('0' + i);
                if (crackSafeDFS(sol, total, v, n, k))
                    return true;
                v.erase(next);
                sol.pop_back();
            }
        }
        return false;
    }
};

//De Bruijn sequence
class Solution {
    int n, k, v;
    vector<vector<bool> > visited;
    string sequence;
public:
    string crackSafe(int n, int k) {
        if (k == 1) return string(n, '0');
        this->n = n;
        this->k = k;
        v = 1;
        for (int i = 0; i < n -1; ++i) v *= k;
        visited.resize(v, vector<bool>(k, false));
        dfs(0);
        return sequence + sequence.substr(0, n - 1);
    }
    
    void dfs(int u) {
        for (int i = 0; i < k; ++i) {
            if (!visited[u][i]) {
                visited[u][i] = true;
                dfs((u * k + i) % v);
                sequence.push_back('0' + i);
            }
        }
    }
};

/*
class Solution {
public:
    vector<int> ret;
    vector<int> a;
    int n, k;

    void db(int t, int p) {
      if (t > n) {
        if (n % p == 0) {
          for (int k = 1; k <= p; ++k) {
            ret.push_back(a[k]);
          }
        }
        return;
      }
      a[t] = a[t - p];
      db(t + 1, p);
      for (int j = a[t - p] + 1; j < k; ++j) {
        a[t] = j;
        db(t + 1, t);
      }
    }

    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        a.resize(k * n);
        ret.clear();
        db(1, 1);
        string ans;
          
          for (auto& it : ret) {
            ans += '0' + it;
          }
          for (int i = 0; i < n - 1; ++i) {
            ans += '0' + ret[i];
          }
          return ans;
    }
};
*/
/*
class Solution {
public:
    void dfs(int cur, vector<string>& node, vector<vector<int> >& tab, vector<bool>& vis, string& ans) {
        int len = (int)tab[cur].size();
        for (int i = 0; i < len; i++) {
            if (!vis[tab[cur][i]]) {
                vis[tab[cur][i]] = true;
                dfs(tab[cur][i], node, tab, vis, ans);
                ans.push_back(node[tab[cur][i]].back());
            }
        }
    }

    string crackSafe(int n, int k) {
        if (n == 1) {
            string ans;
            for (int i = 0; i < k; i++)
                ans.push_back('0' + i);
            return ans;
        } else if (k == 1) {
            return string(n, '0');
        }

        int len = pow(k, n);
        vector<string> node(len, string(n, '0'));
        for (int i = 0; i < len; i++) {
            int N = i, cur = n - 1;
            while (N) {
                node[i][cur--] += N % k;
                N /= k;
            }
        }
        vector<vector<int> > tab(len);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if(i != j && node[i].substr(0, n - 1) == node[j].substr(1))
                    tab[i].push_back(j);
            }
        }
        vector<bool> vis(len, false);
        string ans = node[0].substr(0, n - 1);
        dfs(0, node, tab, vis, ans);
        return ans;
    }
};
*/
