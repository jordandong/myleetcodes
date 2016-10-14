/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Hide Tags Divide and Conquer Linked List Heap
*/

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
