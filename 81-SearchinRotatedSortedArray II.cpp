class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        int n = nums.size();
        if(target == nums[0] || target == nums[n-1]) return true;
    
        int left = 0;
        int right = n - 1;
        while(left < n - 1 && nums[left] == nums[left+1]) left++;
        while(right > 0 && nums[right] == nums[right-1]) right--;
        while(left <= right){
            if(target == nums[left] || target == nums[right]) return true;
            int mid = (left + right) / 2;
            int val = target < nums[0] == nums[mid] < nums[0] ?
                      nums[mid] : (target < nums[0] ? -INFINITY : INFINITY);
            if(target < val)
                right = mid - 1;
            else if (target > val)
                left = mid + 1;
            else
                return true;
        }
        return false;
    }
};
