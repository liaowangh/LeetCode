class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
            if(nums[cur])
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
    }
    // void moveZeroes(vector<int>& nums) {
    //     int lastNonZeroFoundAt = 0;
    //     for(int i = 0; i < nums.size(); ++i)
    //         if(nums[i])
    //             nums[lastNonZeroFoundAt++] = nums[i];
    //     for(int i = lastNonZeroFoundAt; i < nums.size(); ++i)
    //         nums[i] = 0;
    // }
    
    // void moveZeroes(vector<int>& nums) {
    //     // find a zero, then find the first non-zero elment behind
    //     int p = 0;
    //     while(p < nums.size()){
    //         if(nums[p]){
    //             p++;
    //             continue;
    //         }
    //         // nums[p] == 0, find the first non-zero element
    //         for(int i = p + 1; i < nums.size(); ++i){
    //             if(!nums[i]) continue;
    //             swap(nums[i], nums[p]);
    //             break;
    //         }
    //          p++;
    //     }
    // }
};
