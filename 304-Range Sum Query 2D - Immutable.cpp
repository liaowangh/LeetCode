class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size();
        int m = matrix[0].size();
        // acc_sum[i][j]: sumRegion(0,0,i-1,j-1);
        acc_sum = vector<vector<int>>(n+1, vector<int>(m+1,0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                acc_sum[i+1][j+1] = acc_sum[i+1][j] + acc_sum[i][j+1] +
                                    matrix[i][j] - acc_sum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return acc_sum[row2+1][col2+1] - acc_sum[row1][col2+1] - acc_sum[row2+1][col1]
                + acc_sum[row1][col1];
    }
private:
    vector<vector<int>> acc_sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
