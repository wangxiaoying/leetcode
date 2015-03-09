/*

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/


class Solution {
public:
	int search(vector<bool> &flag_col, vector<bool> &flag_l, vector<bool> &flag_r, int row, int n){
		if(row == n){
			return 1;
		}
		
		int ans = 0;
		for(int i = 0; i < n; ++i){
			if(!flag_col[i] && !flag_l[n-1+row-i] && !flag_r[row+i]){
				flag_col[i] = flag_l[n-1+row-i] = flag_r[row+i] = true;
				ans += search(flag_col, flag_l, flag_r, row+1, n);
				flag_col[i] = flag_l[n-1+row-i] = flag_r[row+i] = false;
			}
		}
		return ans;
	}
	
	int totalNQueens(int n) {
		vector<bool> flag_col(n, false);
		vector<bool> flag_l(2*n, false);
		vector<bool> flag_r(2*n, false);
		
		return search(flag_col, flag_l, flag_r, 0, n);
	}
};