class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
    
    bool solve(vector<vector<char>>& board, int row, int col){
        for(int i = row; i < 9; ++i, col = 0){
            for(int j = col; j < 9; ++j){
                if(board[i][j] != '.') continue;
                for(char c = '1'; c <= '9'; ++c){
                    if(isValid(board, i, j, c)){
                        board[i][j] = c;
                        if(solve(board, i, j + 1)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        // check whether filling board[row][col] with c is vaild or not
        for(int i = 0; i < 9; ++i)
            if(board[i][col] == c || board[row][i] == c ||
               board[(row/3)*3+i/3][(col/3)*3+i%3] == c)
                return false; // check column
           
        return true;
    }
};
