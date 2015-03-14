/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/


class Solution {
public:
    bool tracking(vector<vector<char>> &board, string word, int num, int pos_r, int pos_c, vector<vector<bool>> &flag){
        if(word.length() == num) return true;
        if(pos_r < 0 || pos_r >= board.size() || pos_c < 0 || pos_c >= board[0].size()) return false;
        if(flag[pos_r][pos_c] || board[pos_r][pos_c] != word[num]) return false;
        
        flag[pos_r][pos_c] = true;
        if(tracking(board, word, num+1, pos_r-1, pos_c, flag)) return true;
        if(tracking(board, word, num+1, pos_r+1, pos_c, flag)) return true;
        if(tracking(board, word, num+1, pos_r, pos_c-1, flag)) return true;
        if(tracking(board, word, num+1, pos_r, pos_c+1, flag)) return true;
        
        flag[pos_r][pos_c] = false;
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        int rows = (int)board.size();
        if(0 == rows) return false;
        int cols = (int)board[0].size();
        
        vector<vector<bool>> flag(rows, *new vector<bool>(cols, false));
        
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(tracking(board, word, 0, i, j, flag)) return true;
            }
        }
        return false;
    }
};
