/*

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/


class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n-1, mid;
        
        while(left <= right){
            mid = (left + right) / 2;
            if(A[mid] == target) return true;
            if(A[mid] == A[left]){
                left++;
                continue;
            }
            if(A[mid] > A[left]){
                if(A[mid] >= target && A[left] <= target) right = mid-1;
                else left = mid+1;
            }else{
                if(A[mid] <= target && A[right] >= target) left = mid+1;
                else right = mid-1;
            }
        }
        
        return false;
    }
};
