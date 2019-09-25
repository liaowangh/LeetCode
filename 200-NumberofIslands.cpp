class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // use the book[m][n] to denote whether certain lands is included
        // or not. Use BFS to traverse the grid to find all the islands.
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        // modify grid directly to save space
        // vector<vector<int>> book(m);
        // for(int i = 0; i < m; ++i)
        //     book[i] = vector<int>(n, 0);
        // book[i][j] = 1 indicates it is land and had been traversed.
        
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         if(grid[i][j] == '1' && book[i][j] != 1){
        //             count++;
        //             bfs(grid, book, i, j);
        //         }
        //     }
        // }
        return count;
        
    }
    
    void bfs(vector<vector<char>>& grid, int i, int j){
        // east  : i,     j + 1
        // south : i + 1, j
        // west  : i,     j - 1;
        // north : i - 1, j
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            // east
            if(j + 1 < n && grid[i][j+1] == '1'){
                grid[i][j+1] = '0';
                q.push(make_pair(i, j+1));
            }
            
            // south
            if(i + 1 < m && grid[i+1][j] == '1'){
                grid[i+1][j] = '0';
                q.push(make_pair(i+1, j));
            }
            // west
            if(j - 1 >= 0 && grid[i][j-1] == '1'){
                grid[i][j-1] = '0';
                q.push(make_pair(i, j-1));
            }
            // north
            if(i - 1 >= 0 && grid[i-1][j] == '1'){
                grid[i-1][j] = '0';
                q.push(make_pair(i-1, j));
            }
            q.pop();
        }
    }
    
//     void bfs(vector<vector<char>>& grid, vector<vector<int>>& book, int i, int j){
//         // east  : i,     j + 1
//         // south : i + 1, j
//         // west  : i,     j - 1;
//         // north : i - 1, j
//         queue<pair<int, int>> q;
//         q.push(make_pair(i, j));
//         book[i][j] = 1;
//         int m = grid.size();
//         int n = grid[0].size();
//         while(!q.empty()){
//             int i = q.front().first;
//             int j = q.front().second;
//             // east
//             if(j + 1 < n && grid[i][j+1] == '1' && book[i][j+1] != 1){
//                 book[i][j+1] = 1;
//                 q.push(make_pair(i, j+1));
//             }
            
//             // south
//             if(i + 1 < m && grid[i+1][j] == '1' && book[i+1][j] != 1){
//                 book[i+1][j] = 1;
//                 q.push(make_pair(i+1, j));
//             }
//             // west
//             if(j - 1 >= 0 && grid[i][j-1] == '1' && book[i][j-1] != 1){
//                 book[i][j-1] = 1;
//                 q.push(make_pair(i, j-1));
//             }
//             // north
//             if(i - 1 >= 0 && grid[i-1][j] == '1' && book[i-1][j] != 1){
//                 book[i-1][j] = 1;
//                 q.push(make_pair(i-1, j));
//             }
//             q.pop();
//         }
//     }
    
};
