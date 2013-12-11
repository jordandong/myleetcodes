//============================================================================
// Populating Next Right Pointers in Each Node II
// 
// Follow up for problem "Populating Next Right Pointers in Each Node".
//
// What if the given tree could be any binary tree? Would your previous 
// solution still work?
//
// Note:
//
// You may only use constant extra space.
// 
// For example, given the following perfect binary tree:
//  "     1     "
//  "    / \    "
//  "   2   3   "
//  "  / \   \  "
//  " 4  5    7 "
// After calling your function, the tree should look like:
//  "      1 -> NULL      "
//  "     /  \            "
//  "    2 -> 3 -> NULL   "
//  "   / \    \          "
//  "  4-> 5 -> 7 -> NULL "
//============================================================================

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode*> q[2];
        int i=0;
        q[i].push(root);
        while(!q[i].empty()){
            TreeLinkNode* t = q[i].front();
            q[i].pop();
            if(t->left)
                q[i^1].push(t->left);
            if(t->right)
                q[i^1].push(t->right);
            if(q[i].empty()){
                t->next = NULL;
                i^=1;
            }else{
                t->next = q[i].front();
            }
        }
    }
};

#include <iostream>
using namespace std;
/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode 
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution 
{
public:
    void connect(TreeLinkNode *root)
    {
        connect1(root);
    }

    void connect1(TreeLinkNode *curNode)
    {
        if (!curNode)
        	return;
        TreeLinkNode* nextHead = NULL;
        while (curNode)
        {
            if(curNode->left){
                curNode->left->next = getNextSibling(curNode, true);
                if (!nextHead)
                	nextHead = curNode->left;
            }
            if (curNode->right){
                curNode->right->next = getNextSibling(curNode, false);
                if (!nextHead)
                	nextHead = curNode->right;
            }
            curNode = curNode->next;
        }
        connect1(nextHead);
    }

    TreeLinkNode* getNextSibling(TreeLinkNode *curNode, bool isLeft)
    {
        if (isLeft)
            if (curNode->right)
            	return curNode->right;
        while((curNode=curNode->next))
        {
            if (curNode->left)
            	return curNode->left;
            if (curNode->right)
            	return curNode->right;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}
