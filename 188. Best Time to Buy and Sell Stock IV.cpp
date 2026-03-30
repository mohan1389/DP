class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int cap = k, n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));

        for(int buy = 0; buy<=1; buy++){ // when ind == n return 0;
            for(int cap =1; cap<=k; cap++){
                dp[n][buy][cap] = 0;
            }
        }
        for(int ind = 0; ind<n; ind++){ // when cap == 0 return 0;
            for(int buy =0; buy<2; buy++){
                dp[ind][buy][0] = 0;
            }
        }

        for(int ind = n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy){
                        int Buy = -prices[ind] + dp[ind+1][0][cap];
                        int notBuy = 0 + dp[ind+1][1][cap];
                        dp[ind][buy][cap] = max(Buy, notBuy);
                    }
                    else{
                        int sell = prices[ind] + dp[ind+1][1][cap-1];
                        int notSell = 0 + dp[ind+1][0][cap];
                        dp[ind][buy][cap] = max(sell, notSell);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};
