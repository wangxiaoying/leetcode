/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
    ListNode *merge2Lists(ListNode *list1, ListNode *list2){
        if(NULL == list1) return list2;
        if(NULL == list2) return list1;
        
        if(list1->val <= list2->val){
            list1->next = merge2Lists(list1->next, list2);
            return list1;
        }else{
            list2->next = merge2Lists(list1, list2->next);
            return list2;
        }
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(0 == lists.size()) return NULL;
        while(lists.size() > 1){
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin(), lists.begin()+2);
        }
        
        return lists[0];
    }
};