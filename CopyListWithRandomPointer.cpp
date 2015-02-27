/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Hide Tags Hash Table Linked List
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> old_new;
        unordered_map<RandomListNode*, RandomListNode*>::const_iterator got;
        RandomListNode *new_head = new RandomListNode(head->label);
        RandomListNode *cur = head;
        RandomListNode *new_cur = new_head;
        old_new[cur] = new_cur;
        
        while(cur){
            if(cur->random){
                got = old_new.find(cur->random);
                if(got != old_new.end()){
                    new_cur->random = got->second;
                }else{
                    new_cur->random = new RandomListNode(cur->random->label);
                    old_new[cur->random] = new_cur->random;
                }
            }
            
            if(cur->next){
                got = old_new.find(cur->next);
                if(got != old_new.end()){
                    new_cur->next = got->second;
                }else{
                    new_cur->next = new RandomListNode(cur->next->label);
                    old_new[cur->next] = new_cur->next;
                }
            }
            cur = cur->next;
            new_cur = new_cur->next;
        }
        return new_head;
    }
};
