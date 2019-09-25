class Solution {
public:
    string multiply(string num1, string num2) {
        // use a[n] and b[m] to denote int version of  nums1 and nums2 respectively
        // then the nums are \sum a[i]*10^(n-1-i) and \sum b[j]*10^(m-1-j)
        // so the multiply is \sum_{i,j} a[i]*b[j]*10^(n+m-1-(i+j+1))
        // If we use vector<int> res[m+n] to store the result,
        // then a[i]*b[j]*10^(n+m-1-(i+j+1)) is placed at position and i+j+1
        // then we further go through the result array from back to front to
        // deal with the carry.
        if(num1.empty() || num2.empty()) return "";
        int n = num1.size();
        int m = num2.size();
        vector<int> res(m+n,0);
        
        for(int i = n-1; i >= 0; --i)
            for(int j = m-1; j >= 0; --j)
                res[i+j+1] += (num1[i] - '0') * (num2[j] - '0');

        for(int i = m + n - 1; i > 0; --i){
            res[i-1] += res[i] / 10;
            res[i] %= 10;;
        }
        
        int i = 0;
        while(i < m + n && res[i] == 0)
            ++i;
        
        string res_s;
        for( ; i < m+n; ++i)
            res_s.push_back(res[i] + '0');
        return res_s.empty() ? "0" : res_s;
    }
};
