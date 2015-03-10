/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int size_row = (int)obstacleGrid.size();
        if(!size_row) return 0;
        int size_col = (int)obstacleGrid[0].size();
        
        vector<vector<int>> dp(size_row+1, *new vector<int>(size_col+1, 0));
        
        dp[1][1] = 1;
        
        for(int i = 1; i <= size_row; ++i){
            for(int j = 1; j <= size_col; ++j){
                if(obstacleGrid[i-1][j-1]){
                    dp[i][j] = 0;
                    continue;
                }
                
                if(1 == i && 1 == j) continue;
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[size_row][size_col];
    }
};