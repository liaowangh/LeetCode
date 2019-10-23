class Solution {
public:
    // prefix sum + hashmap
    // Let presum[i] = sum(nums[0]-sums[i-1])
    // then presum[j]-presum[i]=sum(nums[i]-sums[j-1])
    // we can use the hashmap to record all the prefix sum,
    // when we encounter a presum[j]-presum[i]==k, we find a subarray sums up to k.
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;
        int count = 0;
        int presum = 0;
        for(int i = 0; i < n; ++i){
            presum += nums[i];
            if(map.count(presum - k)){
                count += map[presum - k];
            }
            map[presum] += 1;
        }
        return count;
    }
    // burte force, 468ms, 9.9MB
    // int subarraySum(vector<int>& nums, int k) {
    //     if(nums.empty()) return 0;
    //     int n = nums.size();
    //     int count = 0;
    //     for(int i = 0; i < n; ++i){
    //         int sum = 0;
    //         for(int j = i; j < n; ++j){
    //             sum += nums[j];
    //             if(sum == k) count++;
    //         }
    //     }
    //     return count;
    // }
};
