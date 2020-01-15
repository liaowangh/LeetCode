class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return string();
        vector<string> numstr;
        for(auto i : nums)
            numstr.push_back(to_string(i));
        sort(numstr.begin(), numstr.end(),
             [](string& s1, string& s2){return s1+s2 > s2+s1;});
        string res;
        for(auto i : numstr)
            res += i;
        while(res[0] == '0' && res.size() > 1)
            res.erase(0,1);
        return res;
    }
            
};
