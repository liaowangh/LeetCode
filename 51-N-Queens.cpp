class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // we fill the board row by row by DFS
        // use a vector<int> book(n, -1) to store the position of the queen
        // in each row, i.e. book(2) = 3 indicates that the quene in row 2
        // is at index 3, -1 indiates no queen yet.
        vector<vector<string>> res;
        if(n == 2 || n == 3) return res;
        vector<string> instance(n); // one solution
        if(n == 1){
            instance[0] = 'Q';
            res.push_back(instance);
            return res;
        }
        for(int i = 0; i < n; ++i)
            instance[i] = string(n, '.');
        vector<int> book(n);
        dfs(res, instance, book, 0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& inst,
             vector<int>& book, int k){
        // we have placed k - 1 queens, now we have to place a queen in k-th row
        if(k == book.size()){
            res.push_back(inst);
            return;
        }
        // if there is a queen in (i,j), then it can attack the position
        // (k,j), (k, j+k-i), (k, j-k+i) at row k.
        // so we use an array safe to store the safe position at row k
        vector<int> safe(book.size(), 1); // 0 indicates not safe
        for(int i = 0; i < k; ++i){
            safe[book[i]] = 0;
            if(book[i]+k-i < book.size()) safe[book[i]+k-i] = 0;
            if(book[i]-k+i >= 0) safe[book[i]-k+i] = 0;
        }
        for(int i = 0; i < book.size(); ++i){
            if(safe[i] == 0) continue;
            inst[k][i] = 'Q';
            book[k] = i;
            dfs(res, inst, book, k+1);
            inst[k][i] = '.';
            //book[k] = 0;
        }
    }
    
};
