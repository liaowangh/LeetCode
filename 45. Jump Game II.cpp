class Solution {
public:
    // 8ms, 10.2MB
    int jump(vector<int>& nums) {
        // shortest path problem
        int n = nums.size();
        int furtherest = 0;
        vector<int> res(n, INT_MAX);
        // res[i] denotes the shortest path from index 0 to index i
        res[0] = 0;
        for(int i = 0; i < n - 1; ++i){
            if(i + nums[i] <= furtherest) continue;
            for(int j = furtherest - i + 1; j <= nums[i] && i + j < n ; ++j)
                res[i+j] = min(res[i] + 1, res[i+j]);
            furtherest = max(furtherest, i + nums[i]);
        }
        return res[n-1];
    }
};
