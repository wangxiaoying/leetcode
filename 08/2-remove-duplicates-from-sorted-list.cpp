/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {
        if(NULL == head) return NULL;
        
        ListNode *now = head;
        
        while(now->next != NULL){
            if(now->val == now->next->val){
                now->next = now->next->next;
            }else{
                now = now->next;
            }
        }
        
        return head;
    }
};