/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        m--;
        n--;
        
        long long ans = 1;
        if(m < n) swap(m, n);
        
        for(int i = 1; i <= n; ++i){
            ans *= (m+i);
            ans /= i;
        }
        
        return int(ans);
    }
};