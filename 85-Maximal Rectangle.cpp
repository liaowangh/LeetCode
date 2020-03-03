class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            res = max(res, maxRectHist(heights));
        }
        return res;
    }
    
    int maxRectHist(vector<int>& heights){
        // problem 84
        if(heights.empty()) return 0;
        int n = heights.size();
        stack<int> stk;
        stk.push(-1);
        int area = 0;
        for(int i = 0; i < n; ++i){
            while(stk.size() > 1 && heights[stk.top()] > heights[i]){
                int height = heights[stk.top()];
                stk.pop();
                area = max(area, (i-stk.top()-1)*height);
            }
            stk.push(i);
        }
        while(stk.size() > 1){
            int height = heights[stk.top()];
            stk.pop();
            area = max(area, (n-stk.top()-1)*height);
        }
        return area;
    }
};
