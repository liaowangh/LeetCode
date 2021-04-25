// for string s, let rs be its reverse string,
// if string t is a prefix of s and also a suffix of rs,
// then t is a palindromic prefix of s
// This task needs to find the longest prefix of s and which is also palindromic
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        string t(s.rbegin(), s.rend());
        int n = s.size();
        vector<int> pi(n, -1); // pi[q] = max{k, k<q and s[0~k] is a suffix of s[0~q]}
        vector<int> psi(n, -1); // psi[q] = max{k, k<=q and s[0~k] is a suffix of t[0~q]}
        
        int k = -1;
        for(int q = 1; q < n; ++q) {
            while(k >= 0 && s[k+1] != s[q])
                k = pi[k];
            if(s[k+1] == s[q])
                k += 1;
            pi[q] = k;
        }
        
        k = -1;
        for(int q = 0; q < n; ++q) {
            while(k >= 0 && s[k+1] != t[q])
                k = pi[k];
            if(s[k+1] == t[q])
                k += 1;
            psi[q] = k;
        }
        return t.substr(0, n-psi[n-1]-1) + s;
    }
};
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         if(s.empty()) return s;
//         string res;
//         int n = s.size();
//         vector<vector<int>> p(n, vector<int>(n)); // p[i][j]=1 means s[i~j] is a palindrome
//         for(int i = 0; i < n; ++i) p[i][i] = 1;
//         for(int i = 0; i < n - 1; ++i) p[i][i+1] = (s[i] == s[i+1]);
//         for(int k = 2; k < n; ++k) {
//             for(int i = 0; i + k < n; ++i) {
//                 p[i][i+k] = p[i+1][i+k-1] && (s[i] == s[i+k]);
//             }
//         }
//         for(int j = n - 1; j >= 0; --j) {
//             if(p[0][j]){
//                 string tmp = s.substr(j+1, n-1-j);
//                 reverse(tmp.begin(), tmp.end());
//                 res = tmp + s;
//                 break;
//             }
//         }
//         return res;
//     }
// };
