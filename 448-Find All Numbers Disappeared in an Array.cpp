class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int tmp = abs(nums[i]) - 1;
            nums[tmp] = nums[tmp] < 0 ? nums[tmp] : -nums[tmp];
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                res.push_back(i+1);
        return res;
    }
    // similar to First Missing Positive, 136ms, 14.9MB
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     // if i appears in nums, then set nums[i-1] to i
    //     if(nums.empty()) return nums;
    //     for(int i = 0; i < nums.size(); ++i){
    //         if(nums[i] == i + 1)
    //             continue;
    //         // then we should set nums[nums[i] - 1] to nums[i];
    //         int cur = nums[i] - 1;
    //         int next;
    //         while(cur + 1 != nums[cur]){
    //             next = nums[cur] - 1;
    //             nums[cur] = cur + 1;
    //             cur = next;
    //         }
    //     }
    //     vector<int> res;
    //     for(int i = 0; i < nums.size(); ++i)
    //         if(nums[i] != i + 1)
    //             res.push_back(i+1);
    //     return res;
    // }
};
