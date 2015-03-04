/*

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/


class Solution {
public:
    int targetIndex(int A[], int n, float target){
        int head = 0, tail = n-1, mid;
        while(head < tail){
            mid = (head + tail) / 2;
            if(A[mid] < target) head = mid + 1;
            else tail = mid;
        }
        return head;
    }

    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        
        int index1 = targetIndex(A, n, target-0.5);
        if(A[index1] != target) return ans;
        
        ans[0] = index1;
        int index2 = targetIndex(A, n+1, target+0.5) - 1;
        ans[1] = index2;
        
        return ans;
    }
};