class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(n == 0) return false;
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        int c = n - 1, r = 0;
        while(c >= 0 && r < m){
            if(matrix[r][c] == target) return true;
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};
