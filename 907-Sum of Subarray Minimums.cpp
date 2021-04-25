// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& A) {
//         if(A.empty()) return 0;
//         int n = A.size();
//         vector<int> Left(n, 0), Right(n, n-1);
//         // Left[i] = min{k, for all k <=j <= i, A[j] >= A[i]}
//         // Right[i] = max{k, for all i <= j <= k, A[j] > A[i]}
//         // then A[i] = min{A[Left[i] ~ Right[i]]}
//         for(int i = 1; i < n; ++i) {
//             int p = i;
//             while(p && A[p-1] >= A[i])
//                 p = Left[p-1];
//             Left[i] = p;
//         }
//         for(int i = n - 2; i >= 0; --i) {
//             int p = i;
//             while(p < n - 1 && A[p+1] > A[i])
//                 p = Right[p+1];
//             Right[i] = p;
//         }
//         int res = 0, m = 1e9+7;
//         for(int i = 0; i < n; ++i) {
//             int tmp = (i - Left[i] + 1) * (Right[i] - i + 1) * A[i];
//             res += tmp;
//             res %= m;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        if(A.empty()) return 0;
        int n = A.size();
        vector<int> left(n), right(n);
        // left[i] = max{j: A[j] < A[i], j < i}, -1 if not exist
        // right[i] = min{j: A[j] > A[i], j > i}, -1 if not exist
        // then A[i] = min{A[LessLeft[i]+1]~A[LessRight[i]-1]}
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < n; ++i) {
            while(stk.size() > 1 && A[stk.top()] > A[i]){
                int x = stk.top();
                stk.pop();
                right[x] = i;
            }
            left[i] = stk.top();
            stk.push(i);
        }
        while(stk.size() > 1){
            int x = stk.top();
            stk.pop();
            right[x] = n;
        }
        int res = 0, m = 1e9+7;
        for(int i = 0; i < n; ++i) {
            int tmp = A[i] * (i - left[i]) * ((right[i] == -1 ? n+1 : right[i]) - i);
            res += tmp;
            res %= m;
        }
        return res;
    }
};
