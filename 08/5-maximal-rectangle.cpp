/*Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.*/

// a brilliant solution I saw in the discuss

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        const int rows = matrix.size();
        const int cols = matrix[0].size();
        
        vector<int> left(cols, 0);
        vector<int> right(cols, cols);
        vector<int> height(cols, 0);
        
        int ans = 0;
        
        for(int i = 0; i < rows; ++i){
            int cur_left = 0, cur_right = cols;
            
            for(int j = 0; j < cols; ++j){
                if('1' == matrix[i][j]) height[j] += 1;
                else height[j] = 0;
            }
            
            for(int j = 0; j < cols; ++j){
                if('1' == matrix[i][j]) left[j] = max(left[j], cur_left);
                else{
                    left[j] = 0;
                    cur_left = j+1;
                }
            }
            
            for(int j = cols-1; j >= 0; --j){
                if('1' == matrix[i][j]) right[j] = min(right[j], cur_right);
                else{
                    right[j] = cols;
                    cur_right = j;
                }
            }
            
            for(int j = 0; j < cols; ++j){
                ans = max(ans, (right[j]-left[j])*height[j]);
            }
            
        }
        
        return ans;
    }
};
