class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1])
            return false;
        // consider as sorted list instead of matrix
        // matrix[row][col] <-> a[row * n + col];
        // a[t] <-> matrix[t/n][t%n]
        int left = 0;
        int right = m * n - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[mid/n][mid%n] == target)
                return true;
            else if(matrix[mid/n][mid%n] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
    //     bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //         if(matrix.empty() || matrix[0].empty()) return false;
    //         int m = matrix.size() - 1;
    //         int n = matrix[0].size() - 1;
    //         if(target < matrix[0][0] || target > matrix[m][n])
    //             return false;
    //         int row = 0;
    //         // target lies in row i,
    //         // then target >= matrix[i][0] && target < matrix[i+1][0]
    //         // use binary search to find the row
    //         if(target >= matrix[m][0] || m == 0)
    //             row = m;
    //         else{
    //             int left = 0;
    //             int right = m;
    //             while(left < right){
    //                 int mid = (left + right) / 2;
    //                 if(target < matrix[mid][0])
    //                     right = mid;
    //                 else if(target < matrix[mid+1][0]){
    //                     row = mid;
    //                     break;
    //                 } else
    //                     left = mid;
    //             }
    //         }
    
    //         if(n == 0) return target == matrix[row][0];
    
    //         // use binary search to find column
    //         int left = 0;
    //         int right = n;
    //         if(matrix[row][left] == target || matrix[row][right] == target)
    //             return true;
    //         while(left < right - 1 ){
    //             int mid = (left + right) / 2;
    //             if(target < matrix[row][mid])
    //                 right = mid;
    //             else if(target == matrix[row][mid])
    //                 return true;
    //             else
    //                 left = mid;
    //         }
    //         return false;
    //     }
};
