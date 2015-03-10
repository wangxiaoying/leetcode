/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(NULL == l1) return l2;
        if(NULL == l2) return l1;
        
        ListNode *head, *now;
        if(l1->val <= l2->val){
            head = l1;
            l1 = l1->next;
        }else{
            head = l2;
            l2 = l2->next;
        }
        now = head;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                now->next = l1;
                now = l1;
                l1 = l1->next;
            }else{
                now->next = l2;
                now = l2;
                l2 = l2->next;
            }
        }
        if(NULL == l1) now->next = l2;
        if(NULL == l2) now->next = l1;
        
        return head;
    }
};