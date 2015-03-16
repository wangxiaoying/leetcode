/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        ListNode *now = new ListNode(0);
        now->next = head;
        ListNode *before = now;
        head = now;
        
        while(NULL != now->next){
            if(now->next->val < x){
                if(now == before){
                    now = now->next;
                    before = now;
                    continue;
                }
                ListNode *temp = now->next;
                now->next = temp->next;
                temp->next = before->next;
                before->next = temp;
                before = temp;
            }else{
                now = now->next;    
            }
        }
        
        return head->next;
    }
};