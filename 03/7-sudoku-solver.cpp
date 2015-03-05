/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/


class Solution {
public:
    const int SIZE = 9;
    
    bool fillIn(vector<vector<char>> &board, int pos, int hrow[9][9], int hcol[9][9], int hgrid[3][3][9]){
        if(pos >= 81) return true;
        
        int x = pos / 9, y = pos % 9;
        
        if('.' != board[x][y]) return fillIn(board, pos+1, hrow, hcol, hgrid);
        
        for(int i = 0; i < SIZE; ++i){
            
            if(hrow[x][i] || hcol[y][i] || hgrid[x/3][y/3][i]) continue;
            
            board[x][y] = '1' + i;
            hrow[x][i] = 1;
            hcol[y][i] = 1;
            hgrid[x/3][y/3][i] = 1;
            
            if(fillIn(board, pos+1, hrow, hcol, hgrid)) return true;
            
            board[x][y] = '.';
            hrow[x][i] = 0;
            hcol[y][i] = 0;
            hgrid[x/3][y/3][i] = 0;
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        if(board.size() != 9 || board[0].size() != 9) return;
        int hrow[9][9] = {{0}}, hcol[9][9] = {{0}}, hgrid[3][3][9] = {{0}};
        int itmp;
        
        for(int i = 0; i < SIZE; ++i){
            for(int j = 0; j < SIZE; ++j){
                if('.' == board[i][j]) continue;
                itmp = board[i][j] - '1';
                hrow[i][itmp] = 1;
                hcol[j][itmp] = 1;
                hgrid[i/3][j/3][itmp] = 1;
            }
        }
        fillIn(board, 0, hrow, hcol, hgrid);
    }
};