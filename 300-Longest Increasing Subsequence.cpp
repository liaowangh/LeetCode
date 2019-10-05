class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        // tail[i] stores the smallest tail of all increasing subsequence
        // with length i+1
        vector<int> tail(n, 0);
        int size = 0; // the length of the LIS
        for(int x : nums){
            // use binary search to find i such that x > tail[i] and x <= tail[i+1]
            // then update tail[i+1] to x
            // if x > tail[size-1], then tail[size] = x, size++
            int i = 0;
            int j = size;
            while(i != j){
                int m = (i + j) / 2;
                if(tail[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            tail[i] = x;
            if(i == size) ++size;
        }
        return size;
    }
    
    // DP, O(n^2)
    // int lengthOfLIS(vector<int>& nums) {
    //     if(nums.empty()) return 0;
    //     vector<int> dp(nums.size(), 1);
    //     for(int i = 1; i < nums.size(); ++i)
    //         for(int j = 0; j < i; ++j)
    //             if(nums[i] > nums[j])
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //     int res = 1;
    //     for(int i = 1; i < nums.size(); ++i)
    //         res = max(res, dp[i]);
    //     return res;
    // }
    
    
//     brute force, too slow
//     int lengthOfLIS(vector<int>& nums) {
//         int max_subseq = 0;
//         stack<int> stk;
//         dfs(nums, stk, 0, max_subseq);
//         return max_subseq;
//     }
    
//     void dfs(vector<int>& nums, stack<int>& stk, int pos, int& max_subseq){
//         // if(pos == nums.size()){
//         //     max_subseq = max(max_subseq, int(stk.size()));
//         //     return;
//         // }
//         if(nums.size() - pos + stk.size() <= max_subseq) return;
//         for(int i = pos; i < nums.size(); ++i){
//             if(stk.empty() || stk.top() < nums[i]){
//                 stk.push(nums[i]);
//                 max_subseq = max(max_subseq, int(stk.size()));
//                 dfs(nums, stk, i + 1, max_subseq);
//                 stk.pop();
//             }
//         }
//     }
    
};
