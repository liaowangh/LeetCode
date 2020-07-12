class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
      
        for(int i = 0; i < nums.size(); ++i){
            // nums[i] is now entering the window,
            // then the window is nums[i-k+1]~nums[i]
            while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
