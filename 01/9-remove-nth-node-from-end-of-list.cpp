/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ptr1 = head, *ptr2 = head;
        if(NULL == head) return NULL;
        
        for(int i = 0; i < n; ++i){
            if(NULL == ptr1) return head;
            ptr1 = ptr1->next;
        }
        
        if(NULL == ptr1){
            return head->next;
        }
        
        while(NULL != ptr1->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr2->next = ptr2->next->next;
        
        return head;
    }
};