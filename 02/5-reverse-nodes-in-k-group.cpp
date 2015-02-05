/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(NULL == head || NULL == head->next || k < 2) return head;
        
        ListNode *tmp = head;
        for(int i = 0; i < k; ++i){
            if(NULL == tmp) return head;
            tmp = tmp->next;
        }
        
        ListNode *tmp1 = head, *tmp2 = head->next, *tmp3=NULL;
        for(int i = 1; i < k; ++i){
            tmp3 = tmp2->next;
            tmp2->next = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp3;
        }
        
        head->next = reverseKGroup(tmp2, k);
        return tmp1;
    }
};