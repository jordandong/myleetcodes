//============================================================================
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
//
//============================================================================


#include <iostream>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return isSymmetric1(root);
    }

    bool isSymmetric1(TreeNode *root) {
        if (root == NULL)
        	return true;
        return isSymmetricHelper1(root->left, root->right);
    }

    bool isSymmetricHelper1(TreeNode *a, TreeNode *b) {
        if (a == NULL || b == NULL)
        	return (a == b);
        return (a->val == b->val)&& isSymmetricHelper1(a->left, b->right)&& isSymmetricHelper1(a->right, b->left);
    }
};

int main() {
    return 0;
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL)
            return true;
        if(root->left == NULL || root->right == NULL)
            return false;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        
        s1.push(root->left);
        s2.push(root->right);
        
        while(!s1.empty() && !s2.empty()){
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();
            s1.pop();
            s2.pop();
            if(n1==NULL && n2!=NULL)
                return false;
            if(n1!=NULL && n2==NULL)
                return false;
            if(n1->val != n2->val)
                return false;
            
            if(n1->left==NULL && n2->right!=NULL)
                return false;
            if(n1->right==NULL && n2->left !=NULL)
                return false;
            if(n1->left!=NULL && n2->right==NULL)
                return false;
            if(n1->right!=NULL && n2->left ==NULL)
                return false;
            if(n1->left!=NULL)
                s1.push(n1->left);
            if(n1->right!=NULL)
                s1.push(n1->right);
            if(n2->right!=NULL)
                s2.push(n2->right);
            if(n2->left!=NULL)
                s2.push(n2->left);
        }
        
        if(!s1.empty() || !s2.empty())
            return false;
        else
            return true;
        
        
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        
        s1.push(root->left);
        s2.push(root->right);
        
        while(!s1.empty()&& !s2.empty()){
            TreeNode* n1 = s1.top();
            TreeNode* n2 = s2.top();
            s1.pop();
            s2.pop();
            if(n1==n2)
                continue;
            if(n1==NULL || n2 ==NULL)
                return n1==n2;
                
            if(n1->val != n2->val)
                return false;
            
            s1.push(n1->left);
            s1.push(n1->right);
            s2.push(n2->right);
            s2.push(n2->left);
        }
        
        if(!s1.empty()||!s2.empty())
            return false;
        else
            return true;
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)
            return true;
        
        vector<int> s1;
        vector<int> s2;
        inorder1(root, s1);
        inorder2(root, s2);
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2)
            return false;
        for(int i=0; i<n1;i++){
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
        
    }
    
    void inorder1(TreeNode *root, vector<int>& s1){
        if(root==NULL)
            return;
        inorder1(root->left, s1);
        s1.push_back(root->val);
        inorder1(root->right, s1);
    }
        
    void inorder2(TreeNode *root, vector<int>&s2){
        if(root==NULL)
            return;
        inorder2(root->right, s2);
        s2.push_back(root->val);
        inorder2(root->left, s2);
    }
};

//Java BST version
public class Solution {
    boolean isSym(ArrayList<TreeNode> al)
    {
        int i=0;
        int j=al.size()-1;
        while(i<j)
        {
            if(al.get(i)==null || al.get(j)==null)
            {
                if(al.get(i)!=al.get(j)) return false;
            }
            else if(al.get(i).val!=al.get(j).val)
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    public boolean isSymmetric(TreeNode root) 
    {
        ArrayList<TreeNode>[] all=new ArrayList[2];
        all[0]=new ArrayList<TreeNode>();
        all[1]=new ArrayList<TreeNode>();
        
        all[0].add(root);
        int i=0;
        
        while(all[i].size()>0)
        {
            if(!isSym(all[i])) return false;
            
            int next=(i+1)%2;
            all[next].clear();
            for(TreeNode n : all[i])
            {
                if(n!=null)
                {
                    all[next].add(n.left);
                    all[next].add(n.right);
                }
            }
            
            i=next;
        }
        
        return true;
    }
}


