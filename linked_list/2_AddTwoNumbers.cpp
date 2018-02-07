/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
    ListNode* addTwoDigit(ListNode* l1, ListNode* l2, int add)
    {
        if(l1 == NULL && l2 == NULL && add == 0)
            return NULL;
        else
        {
            int sum = l1 == NULL ? 0 : l1->val;
            sum += l2 == NULL ? 0 : l2->val;
            sum += add;
            add = sum / 10;
            ListNode* res = new ListNode(sum % 10);
            res->next = addTwoDigit(l1 != NULL ? l1->next : NULL, l2 != NULL ? l2->next: NULL, add);
            return res;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        return addTwoDigit(l1, l2, 0);
    }
};