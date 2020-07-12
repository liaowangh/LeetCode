class Solution{
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);
        for(int i = 0; i <= n; ++i){
            cut[i] = i - 1;
            // to cut s[0~i) into palindromic substings, we need at most i-1 cuts.
        }
        for(int i = 0; i < n; ++i){
            // if s[i-j],...,s[i],...,s[i+j] is palindromic, then cut[i+j+1] can be updated
            // to min(cut[i+j+1], 1+cut[i-j]);
            for(int j = 0; i - j >= 0 && i + j < n && s[i-j] == s[i+j]; ++j){
                cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j]);
            }
            
            // if s[i-j],...,s[i],s[i+1],...,s[i+j+1] is palindromic, then cut[i+j+2] can be
            // updated
            for(int j = 0; i - j >= 0 && i+j+1 < n && s[i+j+1] == s[i-j]; ++j){
                cut[i+j+2] = min(cut[i+j+2], 1+cut[i-j]);
            }
        }
        return cut[n];
    }
};
