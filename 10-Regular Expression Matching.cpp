// Let m = s.size(), n = p.size(), create a matrix match of size (n+1)x(m+1)
// and if s[0~j) matches p[0~i), set match[i][j] to 1, otherwise 0.
// If p[i-1] != '*', then match[i][j] = match[i-1][j-1]
// If p[i-1] = '*', then p[0~i) can be p[0]~p[i-3] or p[0]~p[i-2] or
// p[0]~p[i-2],...,p[i-2] for matching s[0]~s[i-1]
// match[i][j] = match[i-2][j] if p[0]~p[i-3] matches s[0]~s[i-1]
// match[i][j] = match[i-1][j] if p[0]~p[i-2] matches s[0]~s[i-1]
// match[i][j] = match[i][j-1] if p[0]~p[i-2],...,p[i-2] matches s[0]~s[i-2] and
//               (p[i-2] == '.' or p[i-2] == s[j-1])

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() == 0 && p.size() == 0) return true;
        
        int m = s.size();
        int n = p.size();
        vector<vector<int>> match(n+1,vector<int>(m+1,0));
        // match[i][j]: p[0~i) matches s[0~j)
        match[0][0] = 1;
        if(n > 1 && p[1] == '*') match[2][0] = 1;
        for(int i = 1; i <= n; ++i){
            if(i > 1 && p[i-1] == '*') match[i][0] = match[i-2][0];
            for(int j = 1; j <= m; ++j){
                if(p[i-1] == '.' || p[i-1] == s[j-1]){
                    match[i][j] = match[i-1][j-1];
                }else if(p[i-1] == '*'){
                    match[i][j] = match[i-2][j] || match[i-1][j] ||
                        ((p[i-2] == '.' || p[i-2] == s[j-1]) && match[i][j-1]) ;
                }
            }
        }
        return match[n][m];
    }
};
