class Solution {
public:
    double myPow(double x, int n) {
        //return pow(x, n);
        if(n == 0) return 1.;
        if(x == 1.) return 1;
        if(x == -1.) return n % 2 == 0 ? 1 : -1;
        if(n == -1) return 1. / x;
        
        double half = myPow(x, n / 2);
        if(n % 2 == 0)
            return half * half;
        else
            return n > 0 ? half * half * x : 1. / x * half * half;
        
    }
};
