/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/


class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int rows = (int)matrix.size();
		if(0 == rows) return false;
		int cols = (int)matrix[0].size();
		
		if(target < matrix[0][0] || target > matrix[rows-1][cols-1]) return false;
		
		int m;
		int head = 0, tail = rows, mid;
		if(matrix[rows-1][0] < target){
			m = rows-1;
		}else{
			while(head < tail){
				mid = (tail + head) / 2 ;
				if(mid == head) break;
				if(matrix[mid][0] <= target) head = mid;
				else tail = mid;
			}
			m = head;
		}
		
		head = 0, tail = cols;
		while(head < tail){
			mid = (head + tail) / 2;
			if(target == matrix[m][mid]) return true;
			if(target > matrix[m][mid]) head = mid+1;
			else tail = mid;
		}
		
		return false;
	}
};