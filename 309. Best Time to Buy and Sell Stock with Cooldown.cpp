int f(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            int Buy = -prices[ind] + f(ind+1, 0, prices, dp);
            int notBuy = 0 + f(ind+1,1, prices, dp);
            return dp[ind][buy] = max(Buy, notBuy);
        }
        else{
            int sell = prices[ind] + f(ind+2, 1, prices, dp);
            int notSell = 0 + f(ind+1,0, prices, dp);
            return dp[ind][buy] = max(sell, notSell);
        }
    }
