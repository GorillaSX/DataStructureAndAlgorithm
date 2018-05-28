#include <iostream>

using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* swapPairs(ListNode* head)
{
    if(head == NULL and head->next == NULL)
        return NULL;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* tmp = &dummy;
    while(tmp != NULL and tmp->next != NULL and tmp->next->next != NULL)
    {
        ListNode* first = tmp->next;
        tmp->next = tmp->next->next;
        first->next = tmp->next->next;
        tmp->next->next = first;
        tmp = first;
    }
    return dummy.next;
}

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
void insert(ListNode** reshead, ListNode* node)
{
    ListNode dummy(0);
    dummy.next = reshead;
    ListNode* tmp = &dummy;
    while(tmp->next != NULL)
    {
        if(node->val <= tmp->next->val)
        {
            node->next = tmp->next;
            tmp->next = node;
            *reshead = dummy.next;
            return;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    tmp->next = node;
    node->next = NULL;
    *reshead = dummy.next;
}

ListNode* insertionSortList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* reshead = head;
    head = head->next;
    reshead->next = NULL;
    while(head != NULL)
    {
        ListNode* tmp = head;
        head = head->next;
        tmp->next = NULL;
        insert(&reshead, tmp);
    }
    return reshead;

}
