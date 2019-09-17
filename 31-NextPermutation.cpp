class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty() || n == 1) return;
        int i = n - 1;
        while(i >= 1 && nums[i] <= nums[i-1])
            --i;
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = i -1;
        if(nums[j] < nums[n-1])
            i = n - 1;
        else
            while(i < n - 1 && nums[i + 1] > nums[j])
                ++i;
        swap(nums[i], nums[j]);
        reverse(nums.begin() + j + 1, nums.end());
    }
};
