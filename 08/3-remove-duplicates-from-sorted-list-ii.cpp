/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
        
        ListNode *now, *before, *after;
        before = NULL, now = head;
        while(now->next != NULL){
            if(now->val == now->next->val){
                after = now->next->next;
                while(after != NULL && after->val == now->val) after = after->next;
                if(NULL == before) head = after;
                else before->next = after;
                if(NULL == after) break;
                now = after;
            }else{
                before = now;
                now = now->next;
            }
        }
        
        return head;
    }
};