class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty() || k < 0 || t < 0) return false;
        set<long> s;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > k)
                s.erase(nums[i-k-1]);
            auto lb = s.lower_bound((long)nums[i] - t);
            if(lb != s.end() && (long)(*lb) - nums[i] <= t)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
