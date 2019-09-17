class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            
            double num = (nums[mid] < nums[0]) == (target < nums[0])
            ? nums[mid]
            : target < nums[0] ? -INFINITY : INFINITY;
            if(target < num)
                right = mid - 1;
            else if(target > num)
                left = mid + 1;
            else
                return mid;
            
        }
        return -1;
    }
    //     int search(vector<int>& nums, int target) {
    //         if(nums.empty()) return -1;
    //         int n = nums.size();
    //         if(n == 1) return nums[0] == target ? 0 : -1;
    //         return helper(nums, 0, n-1, target);
    //     }
    
    //     int helper(vector<int>& nums, int i, int j, int target){
    //         if(i > j) return -1;
    //         if(nums[i] == target) return i;
    //         if(nums[j] == target) return j;
    //         if(i == j) return nums[i] == target ? i : -1;
    
    //         int mid = (i + j) / 2;
    //         if(nums[mid] == target) return mid;
    
    //         if(nums[mid] > nums[j] && target > nums[j]){
    //             if(target < nums[mid])
    //                 return binarySearch(nums, i, mid - 1, target);
    //             else
    //                 return helper(nums, mid + 1, j, target);
    //         }
    //         else if(nums[mid] <= nums[j] && target <= nums[j]){
    //             if(target < nums[mid])
    //                 return helper(nums, i, mid - 1, target);
    //             else
    //                 return binarySearch(nums, mid + 1, j, target);
    //         }
    //         else if(nums[mid] > nums[j] && target <= nums[j]){
    //             return helper(nums, mid + 1, j, target);
    //         } else
    //             return helper(nums, i, mid - 1, target);
    
    //     }
    
    //     int binarySearch(vector<int>& nums, int i, int j, int target){
    //         // use binary search to search target in num[i]~nums[j]
    //         if(i > j || target > nums[j] || target < nums[i]) return -1;
    //         int left = i;
    //         int right = j;
    //         while(i <= j){
    //             int mid = (left + right) / 2;
    //             if(mid < target)
    //                 left = mid + 1;
    //             else if(mid > target)
    //                 right = mid - 1;
    //             else
    //                 return mid;
    //         }
    //         return -1;
    //     }
};
