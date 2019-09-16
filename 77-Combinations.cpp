class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k > n) return res;
        vector<int> one(k);
        dfs(res, one, 0, n);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int>& one,
             int step, int n){
        if(step == one.size()){
            res.push_back(one);
            return;
        }
        int i = step == 0 ? 1 : one[step - 1] + 1;
        for(; i <= n - one.size() + step + 1; ++i){
            one[step] = i;
            dfs(res, one, step + 1, n);
        }
    }
};
