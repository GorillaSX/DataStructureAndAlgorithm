/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    pair<ListNode*, ListNode*> mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyNode = new ListNode(0);
        ListNode* tmp = dummyNode;
        while(l1 != NULL || l2 != NULL)
        {
            if((l1 != NULL && l2 == NULL) || (l1 != NULL && l2 != NULL && l1->val <= l2->val))
            {
                tmp->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            }
            else if((l1 == NULL && l2 != NULL) || (l1 != NULL && l2 != NULL && l1->val > l2->val))
            {
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        tmp->next = NULL;
        return make_pair(dummyNode->next, tmp);
    }
    ListNode* sortList(ListNode* head) {
        //get the length of List
        int length = 0;
        ListNode* tmp = head;
        while(tmp != NULL)
        {
            length++;
            tmp = tmp->next;
        }
        //calculate the number of stage
        int r = (int)ceil(log2((double)length));
        int len = 1;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        //start 
        for(int i = 0;i < r;i++)
        {
           //calculate the number of merge operation on each stage
           int times = length / 2;
           length = length % 2 != 0 ? (length / 2 + 1) : length / 2;
           //start to merge 
           ListNode* tmp = dummyNode;
           for(int j = 0;j < times;j++)
           {
               ListNode* l1 = tmp->next;
               ListNode* slow = l1;
               int count = len - 1;
               while(count > 0)
               {
                   slow = slow->next;
                   count--; 
               }
               ListNode* l2 = slow->next;
               slow->next = NULL;
               count = len - 1;
               slow = l2;
               while(count > 0 && slow->next != NULL)
               {
                  slow = slow->next; 
                  count--; 
               }
               ListNode* nextHead = slow->next;
               slow->next = NULL;
               auto res = mergeList(l1, l2);
               res.second->next = nextHead;
               tmp->next = res.first;
               tmp = res.second;
           }
           len *= 2; 
        }
        return dummyNode->next; 
    }
};