class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> record;
        int res = 0;
        int left, right;
        for(int i : nums){
            if(record.count(i) == 0){
                left = record.count(i-1) ? record[i-1] : 0;
                right = record.count(i+1) ? record[i+1] : 0;
                int sum = left + right + 1;
                record[i] = sum;
                record[i-left] = sum;
                record[i+right] = sum;
                res = max(res, sum);
            }
        }
        return res;
    }
};
