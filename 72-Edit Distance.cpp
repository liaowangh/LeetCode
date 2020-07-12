class Solution {
public:
    int minDistance(string word1, string word2){
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m+1);
        for(int i = 1; i <= m; ++i) dp[i] = i;
        
        for(int i = 1; i <= n; ++i){
            int pre = dp[0];
            dp[0] = i;
            for(int j = 1; j <= m; ++j){
                int tmp = dp[j];
                if(word1[i-1] == word2[j-1]){
                    dp[j] = pre;
                } else{
                    dp[j] = min(pre, min(dp[j-1], dp[j])) + 1;
                }
                pre = tmp;
            }
        }
        return dp[m];
    }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> dp(n+1, vector<int>(m+1));
    //     // dp[i][j]: minimum number of operations to convert word1[0~i) to word2[0~j)
    //     for(int i = 1; i <= n; ++i){
    //         dp[i][0] = i;  // word1[0~i) to word2[0~0)(empty string)
    //     }
    //     for(int i = 1; i <= m; ++i){
    //         dp[0][i] = i;
    //     }
    //     for(int i = 1; i <= n; ++i){
    //         for(int j = 1; j <= m; ++j){
    //             if(word1[i-1] == word2[j-1]){
    //                 dp[i][j] = dp[i-1][j-1];
    //             }else{
    //                 // 1. w1[0,i-1)->w2[0,j-1), replace w1[i-1] by w2[j-1]
    //                 // 2. w1[0,i-1)->w2[0,j), delete w1[i-1]
    //                 // 3. w1[0,i)->w2[0,j-1), insert w2[j-1]
    //                 dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }
};
