class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        // dp[i] = 1 indicates that substring s[0]-s[i-1] can be broken
        // into dictionary words.
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(auto w : wordDict){
                int len = w.size();
                if(i - len >= 0 && dp[i-len] && s.substr(i-len, len) == w){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     int n = s.size();
    //     vector<int> dp(n+1, 0);
    //     // dp[i] = 1 indicates that substring s[0]-s[i] can be broken
    //     // into dictionary words.
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     dp[0] = 1;
    //     for(int i = 1; i <= n; ++i){
    //         for(int j = 0; j < i; ++j){
    //             if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end()){
    //                 dp[i] = 1;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[n];
    // }
};
