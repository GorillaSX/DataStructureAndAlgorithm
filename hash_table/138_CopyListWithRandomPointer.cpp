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
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        unordered_map<RandomListNode*, RandomListNode*> cor;
        RandomListNode* tmp = head;
        while(tmp != NULL)
        {
            RandomListNode* newNode = new RandomListNode(tmp->label);
            cor[tmp] = newNode;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp != NULL)
        {
            cor[tmp]->next = cor[tmp->next];
            cor[tmp]->random = cor[tmp->random];
            tmp = tmp->next;
        }
        return cor[head];
    }
};