class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()) return 0;
        int n = triangle.size();
        vector<int> minPath = triangle[n-1];
        for(int depth = n - 2; depth >= 0; --depth)
            for(int j = 0; j <= depth; ++j)
                minPath[j] = min(minPath[j], minPath[j+1])
                + triangle[depth][j];
        return minPath[0];
        
    }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int res = 0;
    //     if(triangle.empty()) return res;
    //     res = INFINITY;
    //     dfs(triangle, 0, 0, 0, res);
    //     return res;
    // }
    // // current depth and position
    // void dfs(vector<vector<int>>& triangle, int depth, int pos,
    //          int cursum, int& min){
    //     if(depth == triangle.size() - 1){
    //         min = cursum + triangle[depth][pos] < min ?
    //               cursum + triangle[depth][pos] : min;
    //         return;
    //     }
    //     dfs(triangle, depth + 1, pos, cursum + triangle[depth][pos], min);
    //     dfs(triangle, depth + 1, pos + 1, cursum + triangle[depth][pos],min);
    // }
    
};
