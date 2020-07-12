class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        int start = nums[0];
        int end = start;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == end+1){
                end = nums[i];
            } else{
                string range = to_string(start);
                if(end != start){
                    range += "->";
                    range += to_string(end);
                }
                res.push_back(range);
                start = nums[i];
                end = nums[i];
            }
        }
        string range = to_string(start);
        if(end != start){
            range += "->";
            range += to_string(end);
        }
        res.push_back(range);
        return res;
    }
};
