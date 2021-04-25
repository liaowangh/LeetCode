class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return {};
        int n = nums.size();
        int value1 = nums[0], value2;
        int count1 = 1, count2 = 0;
        for(int i = 1; i < n; ++i) {
            int num = nums[i];
            if(value1 == num)
                count1++;
            else if(value2 == num)
                count2++;
            else if(count1 == 0) {
                value1 = num;
                count1++;
            }
            else if(count2 == 0) {
                value2 = num;
                count2++;
            }
            
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int num: nums) {
            if(num == value1)
                count1++;
            if(num == value2)
                count2++;
        }
        vector<int> res;
        
        if(count1 * 3 > n) res.push_back(value1);
        if(count2 * 3 > n && value2 != value1) res.push_back(value2);
        return res;
    }
};
