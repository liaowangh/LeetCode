class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) return 0;
        int m = s.size();
        int n = t.size();
        
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= m; ++i){
            int pre = dp[0];
            for(int j = 1; j <= min(i, n); ++j){
                int tmp = dp[j];
                dp[j] = dp[j] + (s[i-1] == t[j-1] ? pre : 0);
                pre = tmp;
            }
        }
        return dp[n];
        
        // vector<vector<long long>> dp(m+1, vector<long long>(n+1,0));
        // //dp[i][j]: number of distinct subsequences of s[0~i) which equals t[0~j)
        // for(int i = 0; i <= m; ++i) dp[i][0] = 1;
        // for(int i = 1; i <= m; ++i){
        //     for(int j = 1; j <= min(i,n); ++j){
        //         dp[i][j] = dp[i-1][j] + (s[i-1] == t[j-1] ? dp[i-1][j-1] : 0);
        //     }
        // }
        // return dp[m][n];
    }
};
