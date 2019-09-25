class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n+1, 1);
        vector<int> num(n, 0);
        for(int i = 1; i <= n; ++i){
            num[i-1] = i;
            fact[i] = fact[i-1] * num[i-1];
        }
        string res;
        int pos = k;
        for(int i = n - 1; i > 0; --i){
            int j = (pos - 1) / fact[i];
            res.push_back(num[j] + '0');
            num.erase(num.begin() + j);
            pos -= j * fact[i];
        }
        res.push_back(num[0] + '0');
        return res;
    }
};
