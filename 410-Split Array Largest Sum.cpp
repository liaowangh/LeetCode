// dp[s][j]: result of split array nums[j]~nums[n-1] into s parts
// dp[s+1][i]=min{max(dp[s][j],nums[i]+...+nums[j-1]), i+1<=j<=n-s}
class Solution{
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(n, 0));
        vector<double> prefix_sum(n+1, 0);
        for(int i = 0; i < n; ++i){
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
        }
        for(int j = 0; j < n; ++j){
            dp[1][j] = prefix_sum[n] - prefix_sum[j];
        }
        for(int s = 2; s <= m; s++){
            for(int i = 0; i <= n - s; ++i){
                int res = INT_MAX;
                for(int j = i + 1; j <= n - s + 1; ++j)
                    res = min(res, max(dp[s-1][j], int(prefix_sum[j] - prefix_sum[i])));
                dp[s][i] = res;
            }
        }
        return dp[m][0];
    }
    
};


// class Solution {
// public:
//     // binary search
//     int splitArray(vector<int>& nums, int m) {
//         int max_num = 0;
//         double sum = 0;
//         for(int num : nums){
//             max_num = max(max_num, num);
//             sum += num;
//         }
//         int l = max_num, r = sum; // the answer is between max_num and sum
//         // so we can use binary search
//         while(l < r){
//             int mid = l + (r - l) / 2;
//             if(valid(nums, mid, m)){
//                 // r = mid - 1;
//                 r = mid;
//             } else
//                 l = mid + 1;
//         }
//         return l;
//     }
    
//     // Can we split the array into m subarrays with the sum of each sumarray smaller than
//     // target? If yes, we should lower the target to find the answer, otherwise increase
//     // the target.
//     //
//     // If this returns true, then it means we can split the array into k(<=m) parts and
//     // the sum of each part smaller than target.
//     // If yes, then we have tried our best to make sure each part holds as many
//     // non-negative numbers as we can but we still have numbers left.
//     bool valid(vector<int>& nums, int target, int m){
//         int count = 1;
//         double sum = 0;
//         for(int num : nums){
//             sum += num;
//             if(sum > target){
//                 count++;
//                 // greedy to find the boundary which makes the sum in the subarray
//                 // approaches target most.
//                 sum = num;
//                 if(count > m){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };
