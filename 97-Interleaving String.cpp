class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> IL(m+1, vector<int>(n+1, 0));
        // IL[i][j] : s1[0~i-1) and s2[0~j-1) can form s3[0~i+j) by interleaving
        IL[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            IL[0][i] = IL[0][i-1] && (s3[i-1] == s2[i-1]);
        }
        for(int i = 1; i <= m; ++i){
            IL[i][0] = IL[i-1][0] && (s1[i-1] == s3[i-1]);
            for(int j = 1; j <= n; ++j){
                IL[i][j] = (IL[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                           (IL[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return IL[m][n];
    }
};
