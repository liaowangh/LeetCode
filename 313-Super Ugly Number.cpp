class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> idx(m,0);
        vector<int> ugly(n, INT_MAX);
        ugly[0] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                ugly[i] = min(ugly[i], primes[j]*ugly[idx[j]]);
            for(int j = 0; j < m; ++j)
                idx[j] += primes[j] * ugly[idx[j]] == ugly[i];
        }
        return ugly[n-1];
    }
};
// class Solution {
// public:
//     int nthSuperUglyNumber(int n, vector<int>& primes) {
//         int m = primes.size();
//         int res = 1;
//         vector<int> counter(m, 0);
//         vector<vector<int>> primes_multiple(m);
//         for(int i = 1; i < n; ++i){
//             for(int j = 0; j < m; ++j){
//                 if(INT_MAX / primes[j] > res)
//                     primes_multiple[j].push_back(res * primes[j]);
//             }
//             res = minVal(primes_multiple, counter);
//             for(int j = 0; j < m; ++j)
//                 counter[j] += primes_multiple[j][counter[j]] == res ? 1 : 0;
//         }
//         return res;
//     }
    
//     int minVal(vector<vector<int>> &primes_multiple, vector<int> &counter) {
//         int m = primes_multiple.size();
//         int res = primes_multiple[0][counter[0]];
//         for(int i = 1; i < m; ++i)
//             res = min(res, primes_multiple[i][counter[i]]);
//         return res;
//     }
// };
