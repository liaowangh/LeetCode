class Solution {
public:
    // DP top down: 80ms, 13.8MB
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        vector<int> count(amount, 0);
        return helper(coins, amount, count);
    }
    
    int helper(vector<int>& coins, int rem, vector<int>& count){
        if(rem < 0) return -1;
        if(rem == 0) return 0;
        if(count[rem-1] != 0) return count[rem - 1];
        int tmp = INT_MAX;
        for(int coin : coins){
            int res = helper(coins, rem - coin, count);
            if(res >= 0 && res < tmp)
                tmp = 1 + res;
        }
        count[rem - 1] = tmp == INT_MAX ? -1 : tmp;
        return count[rem - 1];
    }
    //DP Bottom up:  52ms, 12.6MB
    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount == 0) return 0;
    //     vector<int> dp(amount + 1, amount + 1);
    //     // dp[i] record the minimum number of coins to make up i+1
    //     dp[0] = 0;
    //     for(int i = 1; i <= amount; ++i)
    //         for(int j = 0; j < coins.size(); ++j)
    //             if(coins[j] <= i)
    //                 dp[i] = min(dp[i], dp[i-coins[j]] + 1);
    //     return dp[amount] > amount ? -1 : dp[amount];
    // }
};
