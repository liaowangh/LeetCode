class Solution {
public:
    string longestPrefix(string s) {
        if(s.empty()) return s;
        int n = s.size();
        vector<int> pi(n, -1); // pi[q] = max{k, k<q and s[0~k] is a suffix of s[0~q]}
           
        int k = -1;
        for(int q = 1; q < n; ++q) {
            while(k >= 0 && s[k+1] != s[q])
                k = pi[k];
            if(s[k+1] == s[q])
                k += 1;
            pi[q] = k;
        }
        return s.substr(0, pi[n-1] + 1);
    }
};
