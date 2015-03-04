/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {
public:
    int getPivotIndex(int A[], int left, int right){
        int mid = (left + right) / 2;
        if(left == right || A[mid] > A[mid+1]) return mid;
        
        if(A[left] > A[mid]) return getPivotIndex(A, left, mid-1);
        else return getPivotIndex(A, mid+1, right);
    }
    
    int getTargetIndex(int A[], int left, int right, int target){
        if(left > right) return -1;
        
        int mid = (left + right) / 2;
        if(A[mid] == target) return mid;
        
        if(A[mid] < target) return getTargetIndex(A, mid+1, right, target);
        else return getTargetIndex(A, left, mid-1, target);
    }
    
    int search(int A[], int n, int target) {
        if(n <= 0) return -1;
        if(1 == 0 && A[0] != target) return -1;
        
        int pivot_index = getPivotIndex(A, 0, n-1);
        
        if(A[0] <= target && A[pivot_index] >= target) return getTargetIndex(A, 0, pivot_index, target);
        if(A[pivot_index+1] <= target && A[n-1] >= target) return getTargetIndex(A, pivot_index+1, n-1, target);
        
        return -1;
    }
};