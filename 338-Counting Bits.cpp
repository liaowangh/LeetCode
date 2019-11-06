class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for(int i = 1; i <= num; ++i)
            res[i] = res[i&(i-1)] + 1;
        return res;
    }
    // vector<int> countBits(int num) {
    //     vector<int> res(num+1,0);
    //     if(num == 0) return res;
    //     res[1] = 1;
    //     int factor = 2;
    //     for(int i = 2; i <= num; ++i){
    //         if(i - factor >= factor)
    //             factor *= 2;
    //         res[i] = res[i-factor] + 1;
    //     }
    //     return res;
    // }
};
