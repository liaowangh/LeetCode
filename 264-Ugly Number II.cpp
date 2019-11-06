class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 1) return 1;
        // suppose ugly[] stores the n-th ugly number,
        // then all the ugly number must comes from
        // ugly[0] * 2, ugly[1] * 2, ugly[2] * 2, ...
        // ugly[0] * 3, ugly[1] * 3, ugly[2] * 3, ...
        // ugly[0] * 5, ugly[1] * 5, ugly[2] * 5, ...
        // we start from ugly[0] = 1,
        // use t2 to indicate that ugly[t2]*2 has been taken into the ugly array.
        int t2 = 0;
        int t3 = 0;
        int t5 = 0;
        vector<int> ugly(n);
        ugly[0] = 1;
        for(int i = 1; i < n; ++i){
            ugly[i] = min(ugly[t2] * 2, min(ugly[t3] * 3, ugly[t5] * 5));
            if(ugly[i] == ugly[t2]*2) t2++;
            if(ugly[i] == ugly[t3]*3) t3++;
            if(ugly[i] == ugly[t5]*5) t5++;
        }
        return ugly[n-1];
    }
};
