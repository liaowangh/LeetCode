class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> buy(n+1, 0);
               // buy[i] is the max profit up to day i with buy as last action;
        vector<int> sell(n+1, 0);
               // sell[i] is the max profit up to day i with sell as last action.
        buy[1] = -prices[0];
        
        for(int i = 2; i <= n; ++i){
            buy[i] = max(sell[i-2] - prices[i-1], buy[i-1]);
            sell[i] = max(buy[i-1] + prices[i-1], sell[i-1]);
        }
        return sell[n];
    }
    
};
