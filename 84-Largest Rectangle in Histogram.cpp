// Method 1:
// If we can compute the area of the largest rectangle which contains bar i
// (here contain means that the rectangle has height heights[i]), we can find
// the area of largest rectangle by looping all the bars.
// And area of rectangle contains bar i = (lessRight[i]-lessLeft[i]+1)*heights[i]
// where lessRight[i]= max{j>=i: heights[j] >= heights[i]}
//       lessLeft[i] = min{k<=i: heights[k] >= heights[i]}
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        if(heights.size() == 1) return heights[0];
        int n = heights.size();
        vector<int> lessLeft(n), lessRight(n);
        for(int i = 0; i < n; ++i){
            int p = i;
            while(p > 0 && heights[p-1] >= heights[i]){
                p = lessLeft[p-1];
            }
            lessLeft[i] = p;
        }
        for(int i = n - 1; i >= 0; --i){
            int p = i;
            while(p < n - 1 && heights[p+1] >= heights[i])
                p = lessRight[p+1];
            lessRight[i] = p;
        }
        int maxArea = 0;
        for(int i = 0; i < n; ++i){
            maxArea = max(maxArea, (lessRight[i] - lessLeft[i] + 1) * heights[i]);
        }
        return maxArea;
    }
};


// Method 2: Divide and Conquer
// class Solution{
// public:
//     // largest rectangle contains bar[i] and bar[i+1]
//     int areaCross(vector<int>& heights, int l, int r, int i){
//         if(r - l <= 1){
//             return (min(heights[l], heights[r]) * (r - l + 1));
//         }
//         int left = i, right = i + 1;
//         int height = INT_MAX;
//         int max_area = 0;
//         while(true){
//             height = min(height, min(heights[left], heights[right]));
//             max_area = max(max_area, height*(right-left+1));
//             if(left == l && right == r)
//                 break;
//             else if(right == r || (left > l && heights[left-1] >= heights[right+1]))
//                 left--;
//             else
//                 right++;
//         }
//         return max_area;
//     }
    
//     int DivideConquer(vector<int>& heights, int l, int r){
//         if(l == r) return heights[l];
//         int mid = (l + r) / 2;
//         return max(max(DivideConquer(heights, l, mid), DivideConquer(heights, mid+1, r)),
//                    areaCross(heights, l, r, mid));
//     }
    
//     int largestRectangleArea(vector<int>& heights) {
//         if(heights.empty()) return 0;
//         return DivideConquer(heights, 0, heights.size() - 1);
//     }
// };

// Method 3: Using stack
// class Solution{
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         if(heights.empty()) return 0;
//         int n = heights.size();
//         stack<int> stk;
//         stk.push(-1);
//         int max_area = 0;
//         for(int i = 0; i < n; ++i){
//             while(stk.size() > 1 && heights[stk.top()] > heights[i]){
//                 // in this case bar[i-1] is the lessRight[stk.top()]
//                 // and lessLeft is second element in the stack.
//                 int height = heights[stk.top()];
//                 stk.pop();
//                 max_area = max(max_area, height*(i-stk.top()-1));
//             }
//             stk.push(i);
//         }
//         while(stk.size() > 1){
//             int height = heights[stk.top()];
//             stk.pop();
//             max_area = max(max_area, height*(n-stk.top()-1));
//         }
//         return max_area;
//     }
// };

// Method 4: suppose heights[i] = min(heights[...]), then
// maxarea(heights) = max(maxArea(heights[0 ~ i-1]), maxArea(heights[i+1 ~ n-1]),
// maxArea(rectangle contains bar i)), if heights[i] is the minimum, then
// maxArea(rectangle contains bar i) = heights[i] * n
// we can use the segment tree to find the minimum value in any interval.

// struct Node{
//     // the node in a segment tree,
//     // index = argmin{heights[i]: left <= i <= right}
//     int left;
//     int right;
//     int index;
//     Node(){};
//     Node(int l, int r) : left(l), right(r){};
// };

// class Solution{
// public:
//     void buildSegmentTree(vector<Node>& SegTree, vector<int>& heights,
//                           int i, int l, int r){
//         SegTree[i] = Node(l, r);
//         if(l == r){
//             // leaf node
//             SegTree[i].index = l;
//             return;
//         }
//         int mid = (l + r) / 2;
//         buildSegmentTree(SegTree, heights, 2*i + 1, l, mid);  // build left subtree
//         buildSegmentTree(SegTree, heights, 2*i + 2, mid + 1, r); // build right subtree
//         int ind_left = SegTree[2*i+1].index;
//         int ind_right = SegTree[2*i+2].index;
//         SegTree[i].index = heights[ind_left] < heights[ind_right] ? ind_left : ind_right;
//     }
    
//     int query(vector<Node>& SegTree, vector<int>& heights, int i, int l, int r){
//         // get the index of minimum value in heights[l]~heights[r],
//         Node node = SegTree[i];
//         int res;
//         if(l < node.left || r > node.right || l > r)
//             res = INT_MAX;
//         else if(node.left == l && node.right == r)
//             res = node.index;
//         else{
//             int mid = (node.left + node.right) / 2;
//             int ind_left = query(SegTree, heights, i*2+1, l, min(mid, r));
//             int ind_right = query(SegTree, heights, i*2+2, max(mid+1, l), r);
            
//             res = ind_left == INT_MAX ||
//                 (ind_right != INT_MAX && heights[ind_right] < heights[ind_left]) ?
//                 ind_right : ind_left;
//         }
//         return res;
//     }
    
//     int helper(vector<Node>& SegTree, vector<int>& heights, int l, int r){
//         if(l == r) return heights[l];
//         if(l > r) return 0;
//         int min_index = query(SegTree, heights, 0, l, r);
//         int left_area = helper(SegTree, heights, l, min_index - 1);
//         int right_area = helper(SegTree, heights, min_index + 1, r);
//         int cross_area = (r - l + 1) * heights[min_index];
//         return max(max(left_area, right_area), cross_area);
//     }
    
//     int largestRectangleArea(vector<int>& heights) {
//         if(heights.empty()) return 0;
//         int n = heights.size();
//         vector<Node> SegTree(4*n);
//         buildSegmentTree(SegTree, heights, 0, 0, n - 1);
//         return helper(SegTree, heights, 0, n-1);
//     }
// };
