/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

Example:
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();

Hide Tags Reservoir Sampling
*/

// the first element P = 1,
// the second element P = 1/2, the first element P = 1 * 1/2 = 1/2
// 3rd P = 1/3, 2nd P = 1/2 * 2/3 = 1/3, 1st P = 1 * 1/2 * 2/3 = 1/3
// nth P = 1/n, ... ..., 1st P = 1 * 1/2 * 2/3 * ... * n-1/n = 1/n
class Solution {
private:
    ListNode* data;    
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        data = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = -1, cnt = 1;
        ListNode *cur = data;
        while (cur) {
            if (0 == rand()%cnt)
                res = cur->val;
            cur = cur->next;
            cnt++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
