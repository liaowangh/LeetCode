class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int n = nums.size();
        vector<int> a(n);
        // a[i] = k means k-th index can be reached
        // furthest start at the first index
        a[0] = nums[0];
        if(a[0] >= n - 1) return true;
        for(int i = 1; i < n; ++i){
            if(a[i-1] < i) return false;
            a[i] = max(i + nums[i], a[i-1]);
            if(a[i] >= n - 1) return true;
        }
        return false;
    }
};
