/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL)
            return NULL;
            
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        
        return sA(v, 0, v.size()-1);
    }
    
    TreeNode *sA(vector<int> &data, int left, int right){
        if(left>right)
            return NULL;
        
        int mid = (left + right+1)/2;
        TreeNode *t = new TreeNode(data[mid]);
        t->left = sA(data, left, mid-1);
        t->right = sA(data, mid+1, right);
        return t;
    } 
    
};
