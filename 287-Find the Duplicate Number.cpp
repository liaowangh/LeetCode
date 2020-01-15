class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        int mid, count;
        while(l < r){
            mid = (l + r) / 2;
            count = 0;
            for(int i : nums)
                count += i <= mid;
            if(count > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
