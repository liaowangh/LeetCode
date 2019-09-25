class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /**********   sequential   **************/
        // int n = nums.size();
        // for(int i = 1; i < n; ++i){
        //     if(nums[i] < nums[i-1])
        //         return i-1;
        // }
        // return n-1;
        /**********   binary search   **************/
        return helper(nums, 0, nums.size() - 1);
    }
    
    int helper(vector<int>& nums, int lo, int hi){
        if(lo == hi)
            return lo;
        int mid1 = (lo + hi) / 2;
        int mid2 = mid1 + 1;
        if(nums[mid1] > nums[mid2])
            return helper(nums, lo, mid1);
        else
            return helper(nums, mid2, hi);
    }
};
