class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector<int> a(n+1, 0); // a[1]~a[n-1] denote 1~n-1
        int count = 1; // 2 is smallest prime
        for(int i = 3; i < n; i+=2){
            if(a[i] == 0){
                count++;
                for(int j = 1; j <= n / i; j+=2)
                    a[j * i] = 1;
            }
        }
        return count;
    }
};
