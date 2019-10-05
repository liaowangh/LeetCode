class Solution {
public:
    // Idea: for each element in the array, the water it can trap is equal to the
    // minimum of maximum height of bars on both the sides minus its own height
    // dp: use left_max and right_max to store the maximum height of bar from
    // left and from right upto an index i.
    // 8ms, 9.1MB
    int trap(vector<int>& height) {
        if(height.size() < 2) return 0;
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        int res = 0;
        
        left_max[0] = height[0];
        for(int i = 1; i < n; ++i)
            left_max[i] = max(left_max[i-1], height[i]);
        right_max[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; --i)
            right_max[i] = max(right_max[i+1], height[i]);
        for(int i = 1; i < n - 1; ++i)
            res += min(left_max[i], right_max[i]) - height[i];
        return res;
    }
    
    
    // recursive: 8ms, 9.4MB
//     int trap(vector<int>& height) {
//         return helper(height, 0, height.size() - 1);
//     }
    
//     int helper(vector<int>& height, int left, int right){
//         // compute the water trapped by hegith[left]~height[right]
//         if(right - left < 2) return 0;
//         int res = 0;
//         int max_index = left + 1;
//         int max_height = height[max_index];
//         for(int i = left + 1; i < right; ++i){
//             if(height[i] > max_height){
//                 max_height = height[i];
//                 max_index  = i;
//             }
//         }
        
//         int min_bdy = min(height[left], height[right]);
//         if(min_bdy >= max_height)
//             for(int i = left + 1; i < right; ++i)
//                 res += min_bdy - height[i];
//         else
//             res = helper(height, left, max_index) +
//                   helper(height, max_index, right);
//         return res;
//     }
};
