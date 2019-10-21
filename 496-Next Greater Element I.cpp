class Solution {
public:
    // for a decreasing sequence followed a larger number, for example
    // 6 4 3 2 5, 5 is the next larger number of [4,3,2]
    // so we can use a stack to record the decreasing sequence, and when
    // comes up a larger number, pop all the number that is smaller than that.
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> stk;
        for(int num : nums2){
            while(!stk.empty() && stk.top() < num){
                map[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        vector<int> res;
        for(int num : nums1)
            res.push_back(map.find(num) != map.end() ? map[num] : -1);
        return res;
    }
};
