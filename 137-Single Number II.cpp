class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask;
        for(int i : nums){
            x2 ^= x1 & i;
            x1 ^= i;
            mask = ~(x1 & x2);
            x1 &= mask;
            x2 &= mask;
        }
        return x1;
    }
};
