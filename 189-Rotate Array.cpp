class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //nums[i] should went to nums[(i+k)%n]
        int n = nums.size();
        k = k % n;
        if(n == 0 || n == 1 || k == 0) return ;
        int count = 0;
        for(int start = 0; count < n; ++start){
            int current = start;
            int prev = nums[start];
            do{
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while(start != current);
        }
    }
    // slow
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n;
    //     for(int i = 0; i < n - k; ++i)
    //         nums.push_back(nums[i]);
    //     nums.erase(nums.begin(), nums.begin() + n- k);
    // }
};
