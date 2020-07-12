class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int num = 0;
        dfs(res, num, n);
        return res;
    }
    
    void dfs(vector<int>& res, int& num, int k){
        if(k == 0){
            res.push_back(num);
            return;
        }
        dfs(res, num, k-1);
        num ^= 1 << k-1;
        dfs(res, num, k-1);
    }
};
