class Solution {
public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int left = 0;
//         int right = nums.size() - 1;
//         int kth;
//         while(true){
//             int p = partition(nums, left, right);
//             if(p == k - 1){
//                 kth = nums[p];
//                 break;
//             }
//             else if(p < k - 1)
//                 left = p + 1;
//             else
//                 right = p - 1;
//         }
//         return kth;
//     }
    
//     int partition(vector<int>& nums, int i, int j){
//         // as quick sort, put the elements greater than nums[i] in the left,
//         int pivot = nums[i];
//         int l = i + 1;
//         int r = j;
//         while(l <= r){
//             if(nums[l] < pivot && nums[r] > pivot)
//                 swap(nums[r--], nums[l++]);
//             if(nums[l] >= pivot)
//                 l++;
//             if(nums[r] <= pivot)
//                 r--;
//         }
//         swap(nums[i], nums[r]);
//         return r;
//     }
    
/*******************************************************************/
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> pq(nums.begin(), nums.end());
//         for(int i = 1; i < k; ++i)
//             pq.pop();
//         return pq.top();
//     }
    
/*******************************************************************/
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for(int i = 0; i < k - 1; ++i){
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
    
private:
    int heapSize;
    
    int left_child(int i){
        return (i << 1) + 1;
    }
    
    int right_child(int i){
        return (i << 1) + 2;
    }
    
    void maxHeapify(vector<int>& nums, int i){
        int l = left_child(i);
        int r = right_child(i);
        int max_index = i;
        if(l < heapSize && nums[l] > nums[max_index])
            max_index = l;
        if(r < heapSize && nums[r] > nums[max_index])
            max_index = r;
        if(max_index != i){
            swap(nums[i], nums[max_index]);
            maxHeapify(nums, max_index);
        }
    }
    
    void buildMaxHeap(vector<int>& nums){
        heapSize = nums.size();
        for(int i = (heapSize >> 1) - 1; i >= 0; --i)
            maxHeapify(nums, i);
    }
};
