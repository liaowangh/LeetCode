class Solution {
public:
    // also DP, but save a lot of space
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int max_size = 0, prev = 0;
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                int tmp = dp[j];
                if(matrix[i-1][j-1] == '1'){
                    dp[j] = min(dp[j], min(dp[j-1], prev)) + 1;
                    max_size = max(max_size, dp[j]);
                } else
                    dp[j] = 0;
                prev = tmp;
            }
        }
        return max_size * max_size;
    }
    // DP, 16ms, 11.2MB
    // consider dp[i][j] as the size length of the square with the
    // lower-right corner at [i][j], then
    // dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
//     int maximalSquare(vector<vector<char>>& matrix) {
//         if(matrix.empty()) return 0;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         if(n == 0) return 0;
//         vector<vector<int>> dp(m, vector<int>(n,0));
        
//         int max_size = 0;
//         for(int j = 0; j < n; ++j){
//             dp[0][j] = matrix[0][j] - '0';
//             max_size = max(max_size, dp[0][j]);
//         }
//         for(int i = 1; i < m; ++i){
//             dp[i][0] = matrix[i][0] - '0';
//             max_size = max(max_size, dp[i][0]);
//             for(int j = 1; j < n; ++j){
//                 if(matrix[i][j] == '1'){
//                     dp[i][j] = min(dp[i][j-1],
//                                    min(dp[i-1][j], dp[i-1][j-1])) + 1;
//                     max_size = max(max_size, dp[i][j]);
//                 }
//             }
//         }
//         return max_size * max_size;
//     }
};
