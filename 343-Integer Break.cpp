class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        dp[0]=0;
        if(n == 2) return 1;
        for(int i = 3; i <= n; ++i){
            int tmp = max(dp[i-2]*2, dp[i-3]*3);
            tmp = max(tmp, (i-3)*3);
            tmp = max(tmp, (i-2)*2);
            dp[i] = tmp;
        }
        return dp[n];
    }
};
