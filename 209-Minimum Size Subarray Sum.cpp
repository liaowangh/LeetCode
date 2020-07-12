class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), sum = 0, res = INT_MAX;
        while(r < n){
            sum += nums[r++];
            while(sum >= s){
                res = min(res, r - l);
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
//     int minSubArrayLen(int s, vector<int>& nums) {
//         if(nums.empty()) return 0;
//         int n = nums.size();
//         int left = 0, right = 0;
//         int sum = nums[0];
//         while(right < n - 1 && sum < s){
//             sum += nums[++right];
//         }
//         if(sum < s) return 0;
//         int res = right - left + 1;
//         while(true){
//             if(right < n - 1)
//                 sum += nums[++right];
//             while(left <= right && sum - nums[left] >= s){
//                 sum -= nums[left++];
//             }
//             res = min(res, right - left + 1);
//             if(right == n - 1) break;
//         }
//         return res;
        
//     }
};
