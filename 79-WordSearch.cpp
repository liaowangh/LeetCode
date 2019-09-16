class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()) return false;
        if(board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        //int a[m-1][n-1]={0}; // a[i][j]==1 means the letter has been used
        vector<vector<int>> a(m);
        for(int i = 0; i < m; ++i)
            a[i] = vector<int>(n, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                a[i][j] = 1;
                if(board[i][j] == word[0] && dfs(board, word, a, i, j, 1))
                    return true;
                a[i][j] = 0;
            }
        }
        return false;
        
    }
    
    bool dfs(vector<vector<char>>& board, string& word,
             vector<vector<int>>& a, int i, int j, int step){
        if(step == word.size()) return true;
        // east: [i, j] -> [i, j+1]
        if(j + 1 < board[0].size() && a[i][j+1] == 0 &&
           board[i][j+1] == word[step]){
            a[i][j+1] = 1;
            if(dfs(board, word, a, i, j+1, step + 1)) return true;
            a[i][j+1] = 0;
        }
        // south: [i, j] -> [i+1, j]
        if(i+1 < board.size() && a[i+1][j] == 0 &&
           board[i+1][j] == word[step]){
            a[i+1][j] = 1;
            if(dfs(board, word, a, i+1, j, step + 1)) return true;
            a[i+1][j] = 0;
        }
        // west: [i, j] -> [i, j-1]
        if(j-1 >= 0 && a[i][j-1] == 0 &&
           board[i][j-1] == word[step]){
            a[i][j-1] = 1;
            if(dfs(board, word, a, i, j-1, step + 1)) return true;
            a[i][j-1] = 0;
        }
        // north: [i, j] -> [i-1, j]
        if(i-1 >= 0 && a[i-1][j] == 0 &&
           board[i-1][j] == word[step]){
            a[i-1][j] = 1;
            if(dfs(board, word, a, i-1, j, step + 1)) return true;;
            a[i-1][j] = 0;
        }
        return false;
    }
};
