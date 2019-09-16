class Solution {
public:
    int numTrees(int n) {
        //return helper(1, n);
        // try to use DP
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a[n + 1] = {0};
        a[0] = 1;
        a[1] = 1;
        a[2] = 2;
        int res;
        for(int i = 3; i <= n; ++i)
            for(int j = 0; j < i; ++j)
                a[i] += a[j] * a[i - j - 1];
        return a[n];
    }
    
    // too slow
    //     int helper(int start, int end){
    //         // the number of unique BST's that store values start ... end
    //         if(end <= start) return 1;
    //         if(start + 1 == end) return 2;
    //         int res = 0;
    //         for(int i = start; i <= end; ++i)
    //             res += helper(start, i - 1) * helper(i + 1, end);
    //         return res;
    
    //     }
};
