class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int distinct_bit = 1;
        while(!(res & distinct_bit))
            distinct_bit = distinct_bit << 1;
        int res1 = 0;
        for(auto i : nums){
            if(i & distinct_bit)
                res1 ^= i;
        }
        return vector<int>{res1, res^res1};
    }
};
