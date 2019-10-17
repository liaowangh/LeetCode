class Solution {
public:
    // max_sofar record the maximum value of nums[0:i],
    // if nums[i] < max_sofar, then the subarray needs sorting at least ends here.
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_sofar = nums[0];   // traverse from beginning
        int min_sofar = nums[n-1]; // traverse from end
        int end = -2, beg = -1;
        for(int i = 1; i < n; ++i){
            max_sofar = max(max_sofar, nums[i]);
            min_sofar = min(min_sofar, nums[n-i-1]);
            if(max_sofar > nums[i])
                end = i;
            if(min_sofar < nums[n-i-1])
                beg = n-i-1;
        }
        return end < beg ? 0 : end - beg + 1;
    }
};
