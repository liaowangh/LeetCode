class Solution {
public:
    // bit manipulation
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = 1 << n; // p = 2^n
        vector<vector<int>> res(p);
        for(int i = 0; i < p; ++i)
            for(int j = 0; j < n; ++j)
                if( (i >> j) & 1)
                    res[i].push_back(nums[j]);
        return res;
    }
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>> res;
//        if(nums.empty()) return res;
//        vector<int> one;
//        dfs(nums, res, one, -1);
//        return res;
//    }
//
//    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int>& one,
//             int k){
//        res.push_back(one);
//        for(int i = k + 1; i < nums.size(); ++i){
//            one.push_back(nums[i]);
//            dfs(nums, res, one, i);
//            one.pop_back();
//        }
//    }
    
};
