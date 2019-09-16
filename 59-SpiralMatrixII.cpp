class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if(n == 0) return res;
        //if(n == 1) return res.push_back(vector<int>{1});
        res.resize(n);
        for(int i = 0; i < n; ++i)
            res[i].resize(n);
        
        int start = 0;
        int end = n - 1;
        int row;
        int col;
        
        int k = 1;
        while(start <= end){
            for(row = start, col = start; col <= end; ++col)
                res[row][col] = k++;
            
            for(row = start + 1, col = end; row <= end; ++row)
                res[row][col] = k++;
            
            for(col = end - 1, row = end; col >= start; --col)
                res[row][col] = k++;
            
            for(row = end - 1, col = start; row > start; --row)
                res[row][col] = k++;
            
            start++;
            end--;
        }
        return res;
    }
};
