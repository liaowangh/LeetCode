class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.empty() || nums2.empty()) return res;
        unordered_map<int, int> count;
        for(int num : nums1)
            count[num]++;
        for(int num : nums2){
            if(count.find(num) != count.end() && count[num]){
                res.push_back(num);
                count[num]--;
            }
        }
        return res;
    }
};
