/*
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
Each element is either an integer, or a list -- whose elements may also be integers or other lists.
Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
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
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (auto ni : nestedList) {
                if (ni.isInteger())
                    unweighted += ni.getInteger();
                else
                    nextLevel.insert(nextLevel.end(), ni.getList().begin(), ni.getList().end());
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
};
 
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
