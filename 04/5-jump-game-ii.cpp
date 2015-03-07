/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/


class Solution {
public:
    int jump(int A[], int n) {
        if(n <= 1) return 0;
        
        int steps = 0;
        int begin = 0, end = 0, max_reach = 0;
        
        while(max_reach < n-1){
            for(int i = begin; i <= end; ++i){
                max_reach = max(max_reach, A[i] + i);
            }
            begin = end+1;
            end = max_reach;
            steps++;
        }
        
        return steps;
    }
};