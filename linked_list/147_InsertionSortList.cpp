/*
Sort a linked list using insertion sort.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    void insert(ListNode** head, ListNode* node)
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = *head;
        ListNode* tmp = dummyHead;
        while(tmp->next != NULL)
        {
            if(node->val <= tmp->next->val)
            {
                node->next = tmp->next;
                tmp->next = node;
                *head = dummyHead->next;
                return;
            }
            else
            {
                tmp = tmp->next;
            }
        }
        tmp->next = node;
        node->next = NULL;
        *head = dummyHead->next;
    }
    ListNode* insertionSortList(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* resHead = head;
        head = head->next;
        resHead->next = NULL;
        while(head != NULL)
        {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = NULL;
            insert(&resHead, tmp);
        }
        return resHead;
    }
};