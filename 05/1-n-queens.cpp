/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

class Solution {
public:
	vector<string> getMatrix(vector<vector<bool>> &matrix, int n){
		vector<string> ans;
		string s;
		for(int i = 0; i < n; ++i){
			s = "";
			for(int j = 0; j < n; ++j){
				if(matrix[i][j]) s+="Q";
				else s+=".";
			}
			ans.push_back(s);
		}
		return ans;
	}

	void search(vector<vector<string>> &ans, vector<bool> &flag_col, vector<bool> &flag_l, vector<bool> &flag_r,
		vector<vector<bool>> &matrix, int row, int n){
		if(row == n){
			ans.push_back(getMatrix(matrix, n));
			return;
		}
		
		for(int i = 0; i < n; ++i){
			if(!flag_col[i] && !flag_l[n-1+row-i] && !flag_r[row+i]){
				matrix[row][i] = flag_col[i] = flag_l[n-1+row-i] = flag_r[row+i] = true;
				search(ans, flag_col, flag_l, flag_r, matrix, row+1, n);
				matrix[row][i] = flag_col[i] = flag_l[n-1+row-i] = flag_r[row+i] = false;
			}
		}
	}

	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string>> ans;
		vector<bool> flag_col(n, false);
		vector<bool> flag_l(2*n, false);
		vector<bool> flag_r(2*n, false);
		vector<vector<bool>> matrix(n, *new vector<bool>(n, false));
		
		search(ans, flag_col, flag_l, flag_r, matrix, 0, n);
		
		return ans;
	}

};