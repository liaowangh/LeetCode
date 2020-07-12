class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        vector<int> dp(n+1);  //dp[k]:count of numbers of unique digits with length equals k
        dp[0] = 0;
        dp[1] = 10;
        dp[2] = 81;
        for(int i = 3; i <= min(n,10); ++i)
            dp[i] = dp[i-1] * (11-i);
        int res = 0;
        for(int i = 1; i <= min(n, 10); ++i)
            res += dp[i];
        return res;
    }
};
