class Solution {
public:
    int uniquePaths(int m, int n) {
        // the robot has to move down m-1 times and move right n-1 times
        // so the total possible paths are choosen C_{m+n-1}^(m-1)
        if(m == 1 || n == 1) return 1;
        
        int a[m][n] = {0};
        for(int i = 0; i < m; ++i) a[i][0] = 1;
        // a[x][y] = a[x-1][y] + a[x][y-1]
        for(int j = 1; j < n; ++j){
            a[0][j] = 1;
            for(int i = 1; i < m; ++i)
                a[i][j] = a[i-1][j] + a[i][j-1];
        }
        return a[m-1][n-1];
        
        /*************************************************************/
        // to slow
        //return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        /*************************************************************/
        // difficult to handle integer divide
        // int N = m + n - 2;
        // int k = min(m, n) - 1;
        // int res = 1;
        //compute choose k from N
        // for(int i = 0; i < k; ++i){
        //     if( (N - i) % (i + 1) == 0)
        //         res *= (N - i) / (i + 1);
        //     else{
        //         res /= i + 1;
        //         res *= N - i;
        //     }
        // }
        // return res;
        /*************************************************************/
    }
};
