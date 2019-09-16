class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int a[m];
        a[0] = grid[0][0];
        for(int i = 1; i < m; ++i)
            a[i] = grid[i][0] + a[i-1];
        
        for(int j = 1; j < n; ++j){
            a[0] = grid[0][j] + a[0];
            for(int i = 1; i < m; ++i)
                a[i] = grid[i][j] + min(a[i], a[i-1]);
        }
        return a[m-1];
    }
};
