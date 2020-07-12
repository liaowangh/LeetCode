/*
 * Use two bits [2nd bit, 1st bit] to denote [next state, current state]
 * dead -> dead = 00(0)
 * dead -> live = 01(1)
 * live -> dead = 10(2)
 * live -> live = 11(3)
 *
 * Check the current state: board[i][j] & 1
 * Get the next state: board[i][j] >> 1
 *
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                int nbr = live_nbr(board, rows, cols, i, j);
                if(board[i][j] && (nbr == 2 || nbr == 3))
                    board[i][j] = 3;
                else if(!board[i][j] && nbr == 3)
                    board[i][j] = 2;
            }
        }
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                board[i][j] >>= 1;
    }
    
    int live_nbr(vector<vector<int>>& board, int rows, int cols, int i, int j){
        int res = 0;
        for(int p = max(i-1, 0); p <= min(i+1, rows-1); ++p){
            for(int q = max(j-1,0); q <= min(j+1, cols-1); ++q){
                res += board[p][q] & 1;
            }
        }
        res -= board[i][j] & 1;
        return res;
    }
};
