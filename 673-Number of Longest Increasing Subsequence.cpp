class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        vector<int> dp(n, 1);  // dp[i]: length of increasing subsequence ending at nums[i]
        vector<int> count(n); // number of longest subseqence ending at nums[i]
        count[0] = 1;
        int max_len = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j] && dp[i] == dp[j]+1)
                    count[i] += count[j];
            }
            if(dp[i] == 1) count[i] = 1;
            max_len = max(max_len, dp[i]);
        }
        int res = 0;
        for(int i = 0; i < n; ++i)
            if(dp[i] == max_len)
                res += count[i];
        return res;
    }
};
