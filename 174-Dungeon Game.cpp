class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> Hp(m, vector<int>(n,INT_MAX));
        // Hp[i][j]: the minimum HP before entering dungeon[i][j]
        // Hp[i][j] can be calculated based on Hp[i+1][j] and Hp[i][j+1]
        Hp[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : 1 - dungeon[m-1][n-1];
        
        for(int k = 1; k <= m+n-2; ++k){
            int rowcolsum = m+n-2-k;
            for(int i = max(m-k-1, 0); i < m && i <= rowcolsum; ++i){
                int j = rowcolsum - i;
                if(i < m - 1){
                    int tmp = Hp[i+1][j] - dungeon[i][j] <= 0 ? 1 :
                        Hp[i+1][j] - dungeon[i][j];
                    Hp[i][j] = min(Hp[i][j], tmp);
                }
                if(j < n - 1){
                    int tmp = Hp[i][j+1] - dungeon[i][j] <= 0 ? 1 :
                        Hp[i][j+1] - dungeon[i][j];
                    Hp[i][j] = min(Hp[i][j], tmp);
                }
            }
        }
        return Hp[0][0];
    }
};
