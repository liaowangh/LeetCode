class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        pre_sum = vector<int>(n+1);
        for(int i = 0; i < n; ++i)
            pre_sum[i+1] = pre_sum[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return pre_sum[j+1] - pre_sum[i];
    }
    
private:
    vector<int> pre_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
