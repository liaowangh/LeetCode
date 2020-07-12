class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return;
        int n = board.size();
        int m = board[0].size();
        
        for(int j = 0; j < m; ++j){
            if(board[0][j] == 'O')
                fill_boarder(make_pair(0,j), board, n, m);
        }
        
        for(int j = 0; j < m; ++j){
            if(board[n-1][j] == 'O')
                fill_boarder(make_pair(n-1,j), board, n, m);
        }
        
        for(int i = 1; i < n-1; ++i){
            if(board[i][0] == 'O')
                fill_boarder(make_pair(i,0), board, n, m);
        }
    
        for(int i = 1; i < n-1; ++i){
            if(board[i][m-1] == 'O')
                fill_boarder(make_pair(i,m-1), board, n, m);
        }
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
        
    }
    
    void fill_boarder(pair<int,int> pos, vector<vector<char>>& board,
                      int row, int col){
        queue<pair<int,int>> que;
        que.push(pos);
        board[pos.first][pos.second] = '1';
        while(!que.empty()){
            auto cur = que.front();
            que.pop();
            for(auto d : dir){
                int new_i = d.first + cur.first;
                int new_j = d.second + cur.second;
                if(new_i < 0 || new_i == row || new_j < 0 || new_j == col ||
                   board[new_i][new_j] != 'O')
                    continue;
                board[new_i][new_j] = '1';
                que.push(make_pair(new_i, new_j));
            }
        }
    }
};

// class Solution {
// public:
//     vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
//     void solve(vector<vector<char>>& board) {
//         if(board.empty() || board[0].empty()) return;
//         int n = board.size();
//         int m = board[0].size();
        
//         vector<vector<int>> visited(n, vector<int>(m, 0));
//         for(int i = 1; i < n-1; ++i){
//             for(int j = 1; j < m-1; ++j){
//                 if(board[i][j] == 'O' && !visited[i][j]){
//                     bfs(make_pair(i,j), board, visited, n, m);
//                 }
//             }
//         }
//     }
    
//     void bfs(pair<int,int> pos, vector<vector<char>>& board,
//              vector<vector<int>>& visited, int row, int col){
//         vector<pair<int,int>> captured;
//         bool on_board = false;
//         queue<pair<int,int>> que;
//         que.push(pos);
//         while(!que.empty()){
//             pair<int,int> cur = que.front();
//             captured.push_back(cur);
//             // visited[cur.first][cur.second] = 1;
//             que.pop();
            
//             for(auto d : dir){
//                 int new_i = d.first + cur.first;
//                 int new_j = d.second + cur.second;
//                 if(new_i < 0 || new_i == row || new_j < 0 || new_j == col ||
//                    board[new_i][new_j] == 'X' || visited[new_i][new_j])
//                     continue;
//                 if(new_i == 0 || new_i == row-1 || new_j == 0 || new_j == col-1)
//                     on_board = true;
//                 que.push(make_pair(new_i, new_j));
//                 visited[new_i][new_j] = 1;
//             }
//         }
//         if(!on_board){
//             for(auto p : captured)
//                 board[p.first][p.second] = 'X';
//         }
//     }
    
// };
