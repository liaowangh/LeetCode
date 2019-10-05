class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return helper(nums, dp, target);
    }
    
    int helper(vector<int>& nums, vector<int>& dp, int target){
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(target >= nums[i])
                dp[target] += helper(nums, dp, target - nums[i]);
        }
        return dp[target];
        
    }
};
