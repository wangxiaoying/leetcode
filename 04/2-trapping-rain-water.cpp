/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/


class Solution {
public:
    int trap(int A[], int n) {
        int l_pos = 0, r_pos = n-1;
        int l_max = A[0], r_max = A[n-1];
        int ans = 0;
        
        while(l_pos <= r_pos){
            if(l_max <= r_max){
                if(A[l_pos] >= l_max) l_max = A[l_pos];
                else ans += (l_max - A[l_pos]);
                l_pos++;
            }else{
                if(A[r_pos] >= r_max) r_max = A[r_pos];
                else ans += (r_max - A[r_pos]);
                r_pos--;
            }
        }
        return ans;
    }
};