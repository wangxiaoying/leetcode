/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> ans;
		int m = (int)matrix.size();
		if(0 == m) return ans;
		int n = (int)matrix[0].size();
		int row, col;
		
		for(int i = 0; i < min(m/2, n/2); ++i){
			row = i;
			for(col = row; col < n-i-1; ++col){
				ans.push_back(matrix[row][col]);
			}
			col = n-i-1;
			for(row = i; row < m-i-1; ++row){
				ans.push_back(matrix[row][col]);
			}
			row = m-i-1;
			for(col = n-i-1; col > i; --col){
				ans.push_back(matrix[row][col]);
			}
			col = i;
			for(row = m-i-1; row > i; --row){
				ans.push_back(matrix[row][col]);
			}
		}
		
		if(m <= n && 1 == m % 2){
			row = m/2;
			for(col = row; col < n-row; ++col){
				ans.push_back(matrix[row][col]);
			}
		}
		if(n < m && 1 == n % 2){
			col = n/2;
			for(row = col; row < m-col; ++row){
				ans.push_back(matrix[row][col]);
			}
		}
		
		return ans;
	}

};