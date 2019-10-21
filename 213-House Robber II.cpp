class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
    
    int helper(vector<int>& nums, int start, int end){
        int n = end - start + 1;
        int n_2 = 0, n_1 = 0, cur;
        for(int i = start; i <= end; ++i){
            cur = max(n_1, nums[i] + n_2);
            n_2 = n_1;
            n_1 = cur;
        }
        return cur;
        // vector<int> dp(n+1, 0);
        // dp[1] = nums[start];
        // for(int i = 2; i <= n; ++i)
        //     dp[i] = max(dp[i-1], nums[i+start-1] + dp[i-2]);
        // return dp[n];
    }
};
