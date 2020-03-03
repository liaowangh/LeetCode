class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0;
        int right = m;
        int i, j;
        double res;
        while(left <= right){
            i = (left + right) / 2;
            j = (m + n - 2 * i) / 2;
            if(i && nums1[i-1] > nums2[j]){
                right = i - 1;
            } else if (i < m && nums2[j-1] > nums1[i]){
                left = i + 1;
            } else{
                if((m+n) % 2){
                    res = (i == m) ? nums2[j] : min(nums1[i], nums2[j]);
                } else {
                    int max_left = (i == 0) ? nums2[j-1] :
                    (j == 0 ? nums1[i-1] : max(nums1[i-1], nums2[j-1]));
                    int min_right = (i == m) ? nums2[j] :
                    (j == n ? nums1[i] : min(nums1[i], nums2[j]));
                    res = (max_left + min_right) / 2.0;
                }
                break;
            }
        }
        return res;
    }
};
