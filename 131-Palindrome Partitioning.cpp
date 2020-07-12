class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> isPalind(n, vector<int>(n,0));
        // isPalind[i][j] = 1 if s[i~j] is palindromic (i <= j)
        for(int i = 0; i < n - 1; ++i){
            isPalind[i][i] = 1;
            isPalind[i][i+1] = s[i] == s[i+1];
        }
        isPalind[n-1][n-1] = 1;
        for(int j = 2; j < n; ++j){
            for(int i = 0; i + j < n; ++i){
                isPalind[i][i+j] = isPalind[i+1][i+j-1] && (s[i] == s[i+j]);
            }
        }
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(res, isPalind, tmp, s, 0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<vector<int>>& isPalind,
             vector<string>& tmp, string& s, int pos){
        int n = s.size();
        if(pos == n){
            res.push_back(tmp);
            return;
        }
        for(int i = pos; i < n; ++i){
            if(isPalind[pos][i]){
                tmp.push_back(s.substr(pos, i-pos+1));
                dfs(res, isPalind, tmp, s, i+1);
                tmp.pop_back();
            }
        }
    }
};
