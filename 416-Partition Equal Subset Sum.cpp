class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // the problem can transform to find a subset that sums to sum/2
        if(sum & 1) return false;
        int half = sum >> 1;
        vector<int> dp(half + 1, 0);
        // dp[i] stores the number of subsets that sum up to i
        dp[0] = 1;
        for(int i : nums)
            for(int j = half; j >= i; --j)
                dp[j] = dp[j] || dp[j-i];
        return dp[half];
    }
};
