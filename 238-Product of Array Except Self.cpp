class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int left = 1, right = 1;
        for(int i = 1; i < n; ++i){
            left *= nums[i-1];
            res[i] *= left;
            right *= nums[n-i];
            res[n-i-1] *= right;
        }
        return res;
    }
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> res(n, -1);
    //     vector<int> left(n, 1), right(n, 1);
    //     for(int i = 1; i < n; ++i){
    //         left[i] = left[i-1] * nums[i-1];
    //         right[n-i-1] = right[n-i] * nums[n-i];
    //     }
    //     for(int i = 0; i < n; ++i)
    //         res[i] = left[i] * right[i];
    //     return res;
    // }
};
