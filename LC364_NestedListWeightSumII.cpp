/*
TBD
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
class Solution {
public:
    void getLevel(vector<NestedInteger>& nestedList, int level, int& maxLevel) {
        maxLevel = max(level, maxLevel);
        for (NestedInteger ni : nestedList) {
            if (!ni.isInteger()) {
                getLevel(ni.getList(), level + 1, maxLevel);
            }
        }
    }

    int depthSumInverseHelper(vector<NestedInteger>& nestedList, int level) {
        int sum = 0;
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * level;
            } else {
                sum += depthSumInverseHelper(ni.getList(), level - 1);
            }
        }
        return sum;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxLevel = 0;
        getLevel(nestedList, 1, maxLevel);
        return depthSumInverseHelper(nestedList, maxLevel);
    }
};

class Solution {
public:
    void depthSumInverseHelper(vector<NestedInteger>& nestedList, int depth, map<int,int> &M) {
        for(auto ni : nestedList) {
            if(ni.isInteger()) {
                // accumulate all integers in same depth
                if(M.find(depth) == M.end()) {
                    M[depth] = ni.getInteger();
                } else {
                    M[depth] += ni.getInteger();
                }               
            } else {
                depthSumInverseHelper(ni.getList(), depth + 1, M);
            }
        }
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ret = 0;
        map<int, int> M; //sorted
        depthSumInverseHelper(nestedList, 1, M);
        if(M.empty())
            return 0;
        auto it = prev(M.end(), 1);
        int higestDepth = it->first + 1, depth = 1;
        for(auto iter = M.begin(); iter != M.end(); ++iter) {
            depth = higestDepth - iter->first;
            ret += depth*iter->second;
        }
        return ret;
    }
};
