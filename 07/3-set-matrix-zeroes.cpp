/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

*/


class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(0 == n) return;
        int m = matrix[0].size();
        
        int flag = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(0 == matrix[i][j]){
                    matrix[i][0] = 0;
                    if(0 == j) flag = 0;
                    else matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i){
            if(0 == matrix[0][i]){
                for(int j = 0; j < n; ++j) matrix[j][i] = 0;
            }
        }
        for(int i = 0; i < n; ++i){
            if(0 == matrix[i][0]){
                for(int j = 0; j < m; ++j) matrix[i][j] = 0;
            }
        }
        if(0 == flag){
            for(int i = 0; i < n; ++i) matrix[i][0] = 0;
        }
    }
};