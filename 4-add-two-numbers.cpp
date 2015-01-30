/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *merge(ListNode *l1, ListNode *l2, int carry){
        if(NULL == l1 && NULL == l2 && 0 == carry){
            return NULL;
        }
        
        int value = carry;
        ListNode *next1=NULL, *next2=NULL;
        if(NULL != l1){
            value += l1->val;
            next1 = l1->next;
        }
        if(NULL != l2){
            value += l2->val;
            next2 = l2->next;
        }
        
        ListNode *new_node = new ListNode(value%10);
        new_node->next = merge(next1, next2, value/10);
        return new_node;
        
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return merge(l1, l2, 0);
    }
};