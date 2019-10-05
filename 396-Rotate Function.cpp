class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long int res;
        long int n = A.size();
        long int sum = 0;
        long int F = 0;
        for(int i = 0; i < n; ++i){
            F += i * A[i];
            sum += A[i];
        }
        res = F;
        for(int i = 1; i <= n - 1; i++){
            F = F + sum - n * A[n-i];
            res = max(res, F);
        }
        return res;
    }
};
