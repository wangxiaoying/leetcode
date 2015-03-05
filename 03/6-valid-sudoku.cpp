/*

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

*/

class Solution {
public:
	const int SIZE = 9;

	bool insertToMap(map<char, int> &flag, char c){
		if('.' == c) return true;
		flag[c]++;
		if(flag[c] > 1){
			cout<<c<<" false"<<endl;
			return false;
		}
		
//    cout<<c<<" true"<<endl;
		return true;
	}

	bool isValidSudoku(vector<vector<char> > &board) {
		if(board.size() != SIZE) return false;
		if(board[0].size() != SIZE) return false;
		
		map<char, int> flag_row[SIZE];
		map<char, int> flag_col[SIZE];
		map<char, int> flag_grid[SIZE];
		
		for(int i = 0; i < SIZE; ++i){
			for(int j = 0; j < SIZE; ++j){
				char ctmp = board[i][j];
				int index_grid = i / 3 * 3+ j / 3;
//            cout<<ctmp<<" : "<<i<<" "<<j<<" "<<index_grid<<endl;
				if(insertToMap(flag_row[i], ctmp) && insertToMap(flag_col[j], ctmp)
					&& insertToMap(flag_grid[index_grid], ctmp)) continue;
					return false;
			}
		}
		
		return true;
	}


};