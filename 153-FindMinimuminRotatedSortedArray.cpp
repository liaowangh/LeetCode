class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1]) return nums[0];
        // after ruling out the edge case, the index of the
        // minimum value satifies nums[i] < nums[i-1]
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] >= nums[0])
                left = mid + 1;
            else if(nums[mid] < nums[mid - 1])
                return nums[mid];
            else
                right = mid - 1;
        }
        return nums[0];
    }
};
