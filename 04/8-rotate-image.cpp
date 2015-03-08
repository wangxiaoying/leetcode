/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int size = (int)matrix.size();
        int temp;
        for(int i = 0; i < size / 2; ++i){
            for(int j = i; j < size-i-1; ++j){
                temp = matrix[i][j];
                matrix[i][j] = matrix[size-j-1][i];
                matrix[size-j-1][i] = matrix[size-i-1][size-j-1];
                matrix[size-i-1][size-j-1] = matrix[j][size-i-1];
                matrix[j][size-i-1] = temp;
            }
        }
    }
};