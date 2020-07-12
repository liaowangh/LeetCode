class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> inst;
        dfs(res, inst, 1, k, n);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& inst, int i, int k, int n){
        if(n < 0 || (inst.size() == k && n != 0)){
            return;
        } else if(inst.size() == k && n == 0){
            res.push_back(inst);
        } else{
            for(int j = i; j <= 9; ++j){
                inst.push_back(j);
                dfs(res, inst, j+1, k, n-j);
                inst.pop_back();
            }
        }
    }
};
