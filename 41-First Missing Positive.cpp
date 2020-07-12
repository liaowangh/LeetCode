class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int n = nums.size();
      
        int cur;
        int next;
        for(int i = 0; i < n; ++i){
            cur = nums[i];
            while(cur >= 1 && cur <= n && nums[cur-1] != cur){
                next = nums[cur-1];
                nums[cur-1] = cur;
                cur = next;
            }
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
    // // we should return min{x \in Z+, x \notin nums}
    // int firstMissingPositive(vector<int>& nums) {
    //     // Let n be the length of the array, we scan the nums,
    //     // if nums[i] in [n], then set nums[nums[i]-1] to -1.
    //     // then scan the nums again, return the i+1 for the first nums[i] != -1
    //     // if no 0 in nums, then return n+1
    //     if(nums.empty()) return 1;
    //     int n = nums.size();
    //     for(int i = 0; i < n; ++i)
    //         if(nums[i] < 0)
    //             nums[i] = 0;
    //     int cur; // current index
    //     int next;
    //     for(int i = 0; i < n; ++i){
    //         cur = nums[i];
    //         while(cur >= 1 && cur <= n){
    //             // we do not care the number beyond the range
    //             // otherwise, set nums[num[cur]-1] to -1;
    //             next = nums[cur - 1];
    //             nums[cur - 1] = -1;
    //             cur = next;
    //         }
    //     }
    //     for(int i = 0; i < n; ++i)
    //         if(nums[i] != -1) return i + 1;
    //     return n + 1;
    // }
};
