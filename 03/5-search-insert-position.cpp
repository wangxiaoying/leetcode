/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n <= 0) return 0;
        if(A[0] > target) return 0;
        if(A[n-1] < target) return n;
        
        int head = 0, tail = n-1, mid;
        while(head < tail){
            int mid = (head + tail) / 2;
            if(A[mid] < target) head = mid + 1;
            else tail = mid;
        }
        
        return head;
    }
};