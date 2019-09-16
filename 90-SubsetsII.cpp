class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        vector<int> instance;
        sort(nums.begin(), nums.end());
        dfs(res, nums, instance, -1);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& nums,
             vector<int>& instance, int pos){
        if(pos == nums.size()) return;
        res.push_back(instance);
        for(int i = pos + 1; i < nums.size(); ++i){
            instance.push_back(nums[i]);
            dfs(res, nums, instance, i);
            instance.pop_back();
            while(i < nums.size() - 1 && nums[i+1] == nums[i]) ++i;
        }
    }
    
};
