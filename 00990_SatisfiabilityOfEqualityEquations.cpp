/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".
Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

Example 3:

Input: equations = ["a==b","b==c","a==c"]
Output: true

Example 4:

Input: equations = ["a==b","b!=c","c==a"]
Output: false

Example 5:

Input: equations = ["c==c","b==d","x!=z"]
Output: true
 
Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent;
        for (int i = 0; i < 26; i++) {
            parent.push_back(i);
        }

        for (auto eq : equations) {
            int l = eq[0] - 'a', r = eq[3] - 'a';
            if (eq[1] == '=') {
                uni(parent, l, r);
            }  
        }

        for (auto eq : equations) {
            int l = eq[0] - 'a', r = eq[3] - 'a';
            if (eq[1]== '!') {
                if (find(parent, l) == find(parent, r)) {
                    return false;
                }
            }  
        }
        return true;
    }
    
    int find(vector<int> &parent, int c) {
        if (parent[c] == c) {
            return c;
        }
        return find(parent, parent[c]);
    }
    
    void uni(vector<int> &parent, int p, int c) {
        int p1 = find(parent, p);
        int p2 = find(parent, c);
        parent[p2] = p1;
    }
};
