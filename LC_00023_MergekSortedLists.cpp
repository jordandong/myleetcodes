/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []
 

Constraints:
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        
        for (int i = 0; i < lists.size() - 1; i += 2) {
            lists.push_back(merge2Lists(lists[i], lists[i + 1]));
        }
        return lists.back();
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if (l1) {
            cur->next = l1;
        }
        
        if (l2) {
            cur->next = l2;
        }
        
        return dummy->next;
        
    }
};


struct min_heap {
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, min_heap > minHeap;
        int size = lists.size();
        for (int i=0; i<size; i++){
            if (lists[i])
                minHeap.push(lists[i]);
        }
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;
        while (!minHeap.empty()) {
            curr->next = minHeap.top(); // pop the min Node
            minHeap.pop();
            curr = curr->next;
            if (curr->next)
                minHeap.push(curr->next); // push the Node after the min Node if exsits
        }
        curr=head->next;
        delete head;
        return curr;
    }
};
