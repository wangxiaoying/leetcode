/*

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ans(n, *new vector<int>(n, 0));
        int number = 1, row, col;
        for(int i = 0; i < n/2; ++i){
            row = i;
            for(col = i; col < n-i-1; ++col){
                ans[row][col] = number++;
            }
            col = n-i-1;
            for(row = i; row < n-i-1; ++row){
                ans[row][col] = number++;
            }
            row = n-i-1;
            for(col = n-i-1; col > i; --col){
                ans[row][col] = number++;
            }
            col = i;
            for(row = n-i-1; row > i; --row){
                ans[row][col] = number++;
            }
        }
        
        if(1 == n%2){
            ans[n/2][n/2] = number;
        }
        
        return ans;
    }
};