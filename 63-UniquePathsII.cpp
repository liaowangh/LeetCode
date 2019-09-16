class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0][0] == 1 )
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long int a[m][n]={0};
        bool flag = true;
        for(int row = 0; row < m; ++row){
            if(flag == false)
                a[row][0] = 0;
            else if(obstacleGrid[row][0] == 1){
                flag = false;
                a[row][0] = 0;
            } else
                a[row][0] = 1;
        }
        flag = true;
        for(int col = 0; col < n; ++col){
            if(flag == false)
                a[0][col] = 0;
            else if(obstacleGrid[0][col] == 1){
                flag = false;
                a[0][col] = 0;
            } else
                a[0][col] = 1;
        }
        
        for(int col = 1; col < n; col++)
            for(int row = 1; row < m; ++row)
                a[row][col] = obstacleGrid[row][col] == 1 ? 0 :
                a[row-1][col] + a[row][col-1];
        
        return a[m-1][n-1];
    }
    
    // too slow
    // void dfs(vector<vector<int>>& map, int x, int y, int& count){
    //     if(x == map.size() - 1 && y == map[0].size() - 1){
    //         count++;
    //         return;
    //     }
    //     if(y < map[0].size() - 1 && map[x][y+1] == 0)
    //         dfs(map, x, y + 1, count);
    //     if(x < map.size() - 1 && map[x+1][y] == 0)
    //         dfs(map, x + 1, y, count);
    // }
    
};
