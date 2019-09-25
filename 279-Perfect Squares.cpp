class Solution {
public:
    int numSquares(int n) {
        if(n == 1) return 1;
        vector<int> res(n+1, INT_MAX);
        res[0] = 0;
        for(int i = 1; i * i <= n; ++i){
            res[i*i] = 1;
            if(i*i + 1 <= n) res[i*i+1] = 2;
        }
        for(int i = 2; i <= n; ++i){
            if(res[i] != INT_MAX) continue;
            for(int j = 1; j * j <= i; ++j)
                res[i] = min(res[i], res[i - j*j] + 1);
           
        }
        return res[n];
    }
};
