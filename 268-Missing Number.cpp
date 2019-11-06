class Solution {
public:
    // bit manipulation,
    // use the property that a^a = 0, a^0 = a
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i = 0; i < nums.size(); ++i)
            res ^= i ^ nums[i];
        return res;
    }
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     //int sum = accumulate(nums.begin(), nums.end(), 0);
    //     int  sum = 0;
    //     for(int num : nums)
    //         sum += num;
    //     return n * (n + 1) / 2 - sum;
    // }
};
