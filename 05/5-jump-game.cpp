/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/


class Solution {
public:
    bool canJump(int A[], int n) {
        int max_len = 0;
        
        for(int i = 0; i < n && i <= max_len; ++i){
            if(max_len < i + A[i]) max_len = i + A[i];
        }
        
        return max_len >= (n-1);
    }
};