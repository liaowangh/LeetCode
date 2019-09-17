class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else{
                int i = mid - 1;
                int j = mid + 1;
                while(i >= 0 && nums[i] == nums[mid]) --i;
                while(j <= nums.size() - 1 && nums[j] == nums[mid]) ++j;
                res[0] = i + 1;
                res[1] = j - 1;
                return res;
            }
        }
        return res;
    }
};
