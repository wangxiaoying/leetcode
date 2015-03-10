/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if(k <= 0 || NULL == head) return head;
        
        ListNode *ptr1, *ptr2;
        ptr1 = ptr2 = head;
        
        for(int i = 1; i <= k; ++i){
            ptr1 = ptr1->next;
            if(NULL == ptr1){
                k = k % i;
                if(0 == k) return head;
                ptr1 = head;
                for(int j = 0; j < k; ++j){
                    ptr1 = ptr1->next;
                }
                break;
            }
        }
        
        while(ptr1->next != NULL){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr1->next = head;
        head = ptr2->next;
        ptr2->next = NULL;
        
        return head;
    }
};