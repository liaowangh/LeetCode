
class Solution {
public:
    const int base = 1337;
    
    int superPow(int a, vector<int>& b){
        if(b.empty()) return 1;
        a %= base;
        int last_val = b.back();
        b.pop_back();
        return pow(superPow(a, b), 10) * pow(a, last_val) % base;
    }
    
    // computer a^k mod base
    int pow(int a, int k){
        int res = 1;
        for(int i = 0; i < k; ++i)
            res = (a*res) % base;
        return res;
    }
};

/*
 * If a^k = b*q+r, then a^(10*k)=(b*q+r)^10
 * so a^(10*k) mod d = r^10 mod d
 */
// class Solution {
// public:
//     int superPow(int a, vector<int>& b) {
//         int d = 1337; // divisor
//         int n = b.size();
//         a %= d;
//         vector<vector<int>> dp(10, vector<int>(n, 1));
//         // dp[i][j] = a^(i*10^j) mod d
//         for(int i = 1; i < 10; ++i)
//             dp[i][0] = (dp[i-1][0] * a) % d;  // a^(i+1) = a^i * a
//         for(int j = 1; j < n; ++j){
//             int tmp = dp[1][j-1];
//             for(int i = 1; i <= 10; ++i)
//                 // a^(10^i) mod d = (a^(10^(i-1)) mod d)^10 mod d
//                 dp[1][j] = (tmp * dp[1][j]) % d;
//             for(int i = 2; i < 10; ++i)
//                 dp[i][j] = (dp[i-1][j] * dp[1][j]) % d;
//         }
//         int res = 1;
//         for(int i = 0; i < n; ++i)
//             res = (res * dp[b[i]][n-1-i]) % d;
//         return res;
//     }
// };
