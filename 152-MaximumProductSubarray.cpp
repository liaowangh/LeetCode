class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_end_here = nums[0];
        int min_end_here = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != 0){
                int m1 = max_end_here;
                int m2 = min_end_here;
                max_end_here = max(nums[i] * m1,
                                   max(nums[i] * m2, nums[i]));
                min_end_here = min(nums[i] * m1,
                                   min(nums[i] * m2, nums[i]));
                max_so_far = max(max_end_here,
                                 max(min_end_here, max_so_far));
            }
            else{
                max_end_here = 1;
                min_end_here = 1;
                max_so_far = max(0, max_so_far);
                continue;
            }
        }
        return max_so_far;
    }
};
