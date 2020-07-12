class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        // dp[i][j] : the number of combinations that make up amount j using the first i coins
        // dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i]] : 0)
        
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            // dp[i][0] = 1;
            dp[0] = 1;
            for(int j = 1; j <= amount; ++j){
                dp[j] = dp[j] + (j >= coins[i-1] ? dp[j-coins[i-1]] : 0);
                // for(int k = 0; k <= j; k += coins[i-1]){
                    // dp[i][j] += dp[i-1][j-k];
                // }
            }
        }
        // return dp[n][amount];
        return dp[amount];
    }
};
