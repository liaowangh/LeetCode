// suppose i is the last ballon to burst, then its left and right boundary
// is nums[-1] and nums[n] and it divides problems into two subproblems.

class Solution {
public:
    int maxCoins(vector<int>& inums) {
        vector<int> nums;
        nums.push_back(1);
        for(int i : inums)
            if(i) nums.push_back(i);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //dp[i][j]: result of bursting all ballons between i+1~j-1
       
        for(int k = 2; k < n; ++k){
            for(int left = 0; left + k < n; ++left){
                int right = left + k;
                for(int j = left + 1; j < right; ++j){
                    dp[left][right] = max(dp[left][right],
                                          dp[left][j] + dp[j][right] +
                                          nums[left] * nums[j] * nums[right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
