class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        unordered_set<int> s;
        int n = nums.size();
        if(k >= n) k = n - 1;
        for(int i = 0; i < n; ++i) {
            if(i-k-1 >= 0) s.erase(nums[i-k-1]);
            if(s.count(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         if(nums.size() < 2) return false;
//         int n = nums.size();
//         unordered_map<int, vector<int>> m;
//         for(int i = 0; i < n; ++i) {
//             if(m.count(nums[i]) && i - m[nums[i]].back() <= k){
//                 return true;
//             } else{
//                 m[nums[i]].push_back(i);
//             }
//         }
//         return false;
//     }
// };
