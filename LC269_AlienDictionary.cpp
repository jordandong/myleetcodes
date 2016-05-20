/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you.
You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.

For example,
Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Note:
1. You may assume all letters are in lowercase.
2. If the order is invalid, return an empty string.
3. There may be multiple valid order of letters, return any one of them is fine.
*/

//BFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1)
            return words[0];
        graph g = make_graph(words);
        unordered_map<char, int> degrees = compute_indegree(g);
        int numNodes = degrees.size();
        string order;
        queue<char> toVisit;
        for (auto node : degrees)
            if (!node.second)
                toVisit.push(node.first);
        for (int i = 0; i < numNodes; i++) {
            if (toVisit.empty())
                return "";
            char c = toVisit.front();
            toVisit.pop();
            order += c;
            for (char neigh : g[c])
                if (!--degrees[neigh])
                    toVisit.push(neigh);
        }
        return order;
    }
private:
    typedef unordered_map<char, unordered_set<char>> graph;

    graph make_graph(vector<string>& words) {
        graph g;
        int n = words.size();
        for (int i = 1; i < n; i++) {
            bool found = false;
            string word1 = words[i - 1], word2 = words[i];
            int l1 = word1.length(), l2 = word2.length(), l = max(l1, l2);
            for (int j = 0; j < l; j++) {
                if (j < l1 && g.find(word1[j]) == g.end())
                    g[word1[j]] = unordered_set<char>();
                if (j < l2 && g.find(word2[j]) == g.end())
                    g[word2[j]] = unordered_set<char>();
                if (j < l1 && j < l2 && word1[j] != word2[j] && !found) {
                    g[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return g; 
    }

    unordered_map<char, int> compute_indegree(graph& g) {
        unordered_map<char, int> degrees;
        for (auto adj : g) {
            if (!degrees[adj.first]) {}; //set to 0 by constructor
            for (char neigh : adj.second)
                degrees[neigh]++;
        }
        return degrees;
    }
};

//DFS
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1)
            return words[0];
        graph g = make_graph(words);
        return toposort(g);
    }
private:
    typedef unordered_map<char, unordered_set<char>> graph;
    
    graph make_graph(vector<string>& words) {
        graph g;
        int n = words.size();
        for (int i = 1; i < n; i++) {
            bool found = false;
            string word1 = words[i - 1], word2 = words[i];
            int m = word1.length(), n = word2.length(), l = max(m, n);
            for (int j = 0; j < l; j++) {
                if (j < m && g.find(word1[j]) == g.end())
                    g[word1[j]] = unordered_set<char>();
                if (j < n && g.find(word2[j]) == g.end())
                    g[word2[j]] = unordered_set<char>();
                if (j < m && j < n && word1[j] != word2[j] && !found) {
                    g[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return g;
    }
    
    string toposort(graph& g) {
        vector<bool> path(256, false), visited(256, false);
        string topo;
        for (auto adj : g)
            if (!acyclic(g, path, visited, topo, adj.first))
                return "";
        reverse(topo.begin(), topo.end());
        return topo;
    }
    
    bool acyclic(graph& g, vector<bool>& path, vector<bool>& visited, string& topo, char node) {
        if (path[node])
            return false;
        if (visited[node])
            return true;
        path[node] = visited[node] = true;
        for (auto neigh : g[node])
            if (!acyclic(g, path, visited, topo, neigh))
                return false;
        path[node] = false;
        topo += node;
        return true;
    }
};

// Time:  O(n)
// Space: O(|V|+|E|) = O(26 + 26^2) = O(1)
// BFS solution.
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> nodes;
        unordered_map<char, unordered_set<char>> in_degree, out_degree;
        queue<char> zero_in_degree_queue;
        for (const auto& word : words) {
            for (const auto& c : word) {
                nodes.emplace(c);
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            findEdges(words[i - 1], words[i], &in_degree, &out_degree);
        }
        for (const auto& node : nodes) {
            if (in_degree.find(node) == in_degree.end()) {
                zero_in_degree_queue.emplace(node);
            }
        }

        // BFS
        string result;
        while (!zero_in_degree_queue.empty()) {
            const auto& precedence = zero_in_degree_queue.front();
            zero_in_degree_queue.pop();
            result.push_back(precedence);
            
            if (out_degree.find(precedence) != out_degree.end()) {
                for (const auto& c : out_degree[precedence]) {
                    in_degree[c].erase(precedence);
                    if (in_degree[c].empty()) {
                        zero_in_degree_queue.emplace(c);
                    }
                }
                out_degree.erase(precedence);
            }
        }
        
        if (!out_degree.empty()) {
            return "";
        }
        
        return result;
    }

private:
    // Construct the graph.
    void findEdges(const string &word1, const string &word2,
                   unordered_map<char, unordered_set<char>> *in_degree,
                   unordered_map<char, unordered_set<char>> *out_degree) {
        const int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                (*in_degree)[word2[i]].emplace(word1[i]);
                (*out_degree)[word1[i]].emplace(word2[i]);
                break;
            }
        }
    }
};

// DFS solution.
class Solution {
public:
    string alienOrder(vector<string>& words) {
        // Find ancestors of each node by DFS.
        unordered_set<char> nodes;
        unordered_map<char, vector<char>> ancestors;
        for (int i = 0; i < words.size(); ++i) {
            for (const auto& c : words[i]) {
                nodes.emplace(c);
            }
            if (i > 0) {
                findEdges(words[i - 1], words[i], &ancestors);
            }
        }

        // Output topological order by DFS.
        string result;
        unordered_map<char, char> visited;
        for (const auto& node : nodes) {
            if (topSortDFS(node, node, &ancestors, &visited, &result)) {
                return "";
            }
        }
        
        return result;
    }

private:
    // Construct the graph.
    void findEdges(const string &word1, const string &word2,
                   unordered_map<char, vector<char>> *ancestors) {
        const int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                (*ancestors)[word2[i]].emplace_back(word1[i]);
                break;
            }
        }
    }

    // Topological sort, return whether there is a cycle.
    bool topSortDFS(const char& root,
                    const char& node,
                    unordered_map<char, vector<char>> *ancestors,
                    unordered_map<char, char> *visited,
                    string *result) {
        if (visited->emplace(make_pair(node, root)).second) {
            for (auto& ancestor: (*ancestors)[node]) {
                if (topSortDFS(root, ancestor, ancestors, visited, result)) {
                    return true;
                }
            }
            result->push_back(node);
        } else if ((*visited)[node] == root) {
            // Visited from the same root in the DFS path.
            // So it is cyclic.
            return true;
        }
        return false;
    } 
};

// DFS with adjacency matrix solution.
class Solution {
public:
    string alienOrder(vector<string>& words) {
        string result;
        vector<vector<bool>> graph(26, vector<bool>(26));
        findDependency(words, &graph);
        findOrder(&graph, &result);
        return result;
    }

private:
    void findEdges(const string &word1, const string &word2, vector<vector<bool>> *graph) {
        const int len = min(word1.length(), word2.length());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                (*graph)[word1[i] - 'a'][word2[i] - 'a'] = true;
                break;
            }
        }
    }

    // Construct the graph.
    void findDependency(const vector<string>& words, vector<vector<bool>> *graph) {
        for (const auto& c : words[0]) {
            (*graph)[c - 'a'][c - 'a'] = true;
        }
        for (int i = 1; i < words.size(); ++i) {
            for (const auto& c : words[i]) {
                (*graph)[c - 'a'] [c - 'a'] = true;
            }
            findEdges(words[i - 1], words[i], graph);
        }
    }

    // Topological sort, return whether there is a cycle.
    bool topSortDFS(string *result, vector<bool> *visited,
                    vector<vector<bool>> *graph, const int root) {
        if ((*visited)[root]) {
            result->clear();
            return true;
        }
        (*visited)[root] = true;
        for (int i = 0; i < 26; ++i) {
            if (i != root && (*graph)[root][i]) {
                if (topSortDFS(result, visited, graph, i)) {
                    return true;
                }
            }
        }
        (*graph)[root][root] = false;
        result->push_back(root + 'a');
        return false;
    }  

    void findOrder(vector<vector<bool>> *graph, string *result) {
        for (int i = 0; i < 26; ++i) {
            // Find a root node.
            bool root_node = (*graph)[i][i];
            if ((*graph)[i][i]) {
                for (int j = 0; j < 26; ++j) {
                    if (j != i && (*graph)[j][i]) {
                        root_node = false;
                        break;
                    }
                }
            }
            if (root_node) {
                string reversed_order = "";
                vector<bool> visited(26, false);
                if (topSortDFS(&reversed_order, &visited, graph, i)) {
                    result->clear();
                    return;
                } else {
                    result->append(reversed_order);
                }
            }
        }

        // If there is any unvisited node, return "".
        for (int i = 0; i < 26; ++i) {
            if ((*graph)[i][i]) {
                result->clear();
                return;
            }
        }
        // The order should be reversed.
        reverse(result->begin(), result->end());
    }
};
