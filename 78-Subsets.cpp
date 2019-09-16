class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> one;
        dfs(nums, res, one, -1);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>> &res, vector<int>& one,
             int k){
        res.push_back(one);
        for(int i = k + 1; i < nums.size(); ++i){
            one.push_back(nums[i]);
            dfs(nums, res, one, i);
            one.pop_back();
        }
    }
    
};
