class Solution {
public:
    double myPow(double x, int n){
        if(x == 0) return 0;
        if(n == 0) return 1;
        long long p = n;
        if(n < 0){
            p = -p;
            x = 1. / x;
        }
        double res = 1.;
        while(p > 0){
            if(p & 1) res *= x;
            p >>= 1;
            x *= x;
        }
        return res;
    }
//     double myPow(double x, int n) {
//         //return pow(x, n);
//         if(n == 0) return 1.;
//         if(x == 1.) return 1;
//         if(x == -1.) return n % 2 == 0 ? 1 : -1;
//         if(n == -1) return 1. / x;
        
//         double half = myPow(x, n / 2);
//         if(n % 2 == 0)
//             return half * half;
//         else
//             return n > 0 ? half * half * x : 1. / x * half * half;
        
//     }
};
