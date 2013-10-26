/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!head)
            return NULL;
        
        unordered_map<RandomListNode*, RandomListNode*> old_new;
        unordered_map<RandomListNode*, RandomListNode*>::const_iterator got;
        RandomListNode *new_head = new RandomListNode(head->label);
        RandomListNode *tmp = head;
        RandomListNode *new_tmp = new_head;
        old_new.insert(make_pair(tmp, new_tmp));
        
        while(tmp->next || tmp->random){
            if(tmp->next){
                got=old_new.find(tmp->next);
                if(got!=old_new.end()){
                    new_tmp->next = got->second;
                }else{
                    new_tmp->next = new RandomListNode(tmp->next->label);
                    old_new.insert(make_pair(tmp->next, new_tmp->next));
                }
            }
            
            if(tmp->random){
                got=old_new.find(tmp->random);
                if(got!=old_new.end()){
                    new_tmp->random = got->second;
                }else{
                    new_tmp->random = new RandomListNode(tmp->random->label);
                    old_new.insert(make_pair(tmp->random, new_tmp->random));
                }
            }
            if(!tmp->next)
                break;
            tmp=tmp->next;
            new_tmp=new_tmp->next;
        }
        return new_head;
    }
};
