class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int value = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(count == 0) {
                value = nums[i];
                count = 1;
            } else {
                count += nums[i] == value ? 1 : -1;
            }
        }
        return value;
    }
    // int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> count;
    //     for(int num : nums){
    //         if(++count[num] > nums.size() / 2)
    //             return num;
    //     }
    //     return 0;
    // }
};
