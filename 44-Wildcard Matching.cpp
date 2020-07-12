class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<int> match(m+1,0);
        match[0] = 1;
        for(int i = 1; i <= n; ++i){
            int pre = match[0];
            match[0] = (p[i-1] == '*') && match[0];
            for(int j = 1; j <= m; ++j){
                int tmp = match[j];
                if(p[i-1] != '*'){
                    match[j] = pre && (p[i-1] == '?' || p[i-1] == s[j-1]);
                } else{
                    match[j] = match[j] || match[j-1];
                }
                pre = tmp;
            }
        }
        return match[m];
        // vector<vector<int>> match(n+1, vector<int>(m+1,0));
        // match[0][0] = 1;
        // for(int i = 1; i <= n; ++i){
        //     if(p[i-1] == '*') match[i][0] = match[i-1][0];
        //     for(int j = 1; j <= m; ++j){
        //         if(p[i-1] == '?' || p[i-1] == s[j-1]){
        //             match[i][j] = match[i-1][j-1];
        //         } else if(p[i-1] == '*'){
        //             match[i][j] = match[i-1][j] || match[i][j-1];
        //         }
        //     }
        // }
        // return match[n][m];
    }
};
