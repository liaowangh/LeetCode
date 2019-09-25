class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = s[0] == '0' ? 0 : 1;
        for(int i = 1; i < n; ++i){
            int num = s[i] - '0' + (s[i-1]-'0') * 10;
            res[i+1] = (s[i] == '0' ? 0 : res[i]) +
                       (num <= 26 && num > 9 ? res[i-1] : 0);
        }
        return res[n];
    }
};
