class Solution {
public:
    // DP, make use of a dp array where i-th element of dp represents the length
    // of the longest vaild substring ending at i-th index.
    // 1. s[i]=')' and s[i-1] = '(', dp[i] = dp[i-2] + 2
    // 2. s[i]=')' and s[i-1] = ')', if s[i-dp[i-1]-1]='(' then
    //    dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int res = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i){
            if(s[i] == ')' && s[i-1] == '('){
                dp[i] = i > 1 ? dp[i-2] + 2 : 2;
                res = max(res, dp[i]);
            }
            if(s[i] == ')' && s[i-1] == ')' &&
               i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '('){
                dp[i] = dp[i-1] + ((i-dp[i-1]>=2) ? dp[i-dp[i-1]-2]:0 )+ 2;
                res = max(res, dp[i]);
            }
        }
        return res;
    }
    // Using a stack to store the index of the non-valid
    // int longestValidParentheses(string s) {
    //     if(s.empty()) return 0;
    //     int res = 0;
    //     stack<int> stk;
    //     stk.push(-1);
    //     for(int i = 0; i < s.size(); ++i){
    //         if(s[i] == '(')
    //             stk.push(i);
    //         else{
    //             stk.pop();
    //             if(stk.empty()) stk.push(i);
    //             res = max(res, i - stk.top());
    //         }
    //     }
    //     return res;
    // }
};
