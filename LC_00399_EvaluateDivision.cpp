/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number).
Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> euqations, vector<double>& values, vector<pair<string, string>> query .
where equations.size() == values.size(),the values are positive. 
this represents the equations.return vector<double>. . 
The example above:
equations = [ ["a", "b"], ["b", "c"] ].
values = [2.0, 3.0].
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].

The input is always valid.
You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

// T : O(E + q * |V|), |V| is the number of variables
// S : O(E)
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
        vector<double>& values, vector<pair<string, string>> query) {

        unordered_map<string, unordered_map<string, double>> lookup;
        for (int i = 0; i < values.size(); ++i) {
            lookup[equations[i].first].emplace(equations[i].second, values[i]);
            if (values[i] != 0) {
                lookup[equations[i].second].emplace(equations[i].first, 1 / values[i]);
            }
        }

        vector<double> result;
        for (const auto& i : query) {
            unordered_set<string> visited;
            const auto tmp = check(i.first, i.second, lookup, &visited);
            result.emplace_back(tmp.second);
        }
        return result;
    }

private:
    pair<bool, double> check(string up, string down, 
            unordered_map<string, unordered_map<string, double>> &lookup,
            unordered_set<string> *visited) {
        if (lookup[up].find(down) != lookup[up].end()) {
            return {true, lookup[up][down]};
        }
        for (const auto& q : lookup[up]) {
            if (!visited->count(q.first)) {
                visited->emplace(q.first);
                const auto tmp = check(q.first, down, lookup, visited);
                if (tmp.first) {
                    return {true, q.second * tmp.second};
                }
            }
        }
        return {false, -1};
    }
};
