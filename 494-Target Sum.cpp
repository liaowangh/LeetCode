class Solution {
public:
    // divid into P(positive) and N(negative),
    // then it requires sum(P)-sum(N)=S which is equivalent to
    // sum(P)+sum(N)+sum(P)-sum(N)=S+sum(P)+sum(N)
    // =>2*sum(P)=S+sum(nums)
    // => sum(P)=(S+sum(nums))/2
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || -sum > S) return 0;
        if((S+sum) & 1) return 0;
        int target = (S+sum) >> 1;
        // dp[i] records the number of subsets that sum up to i
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int num : nums)
            for(int i = target; i >= num; --i)
                dp[i] += dp[i-num];
        return dp[target];
    }
};
