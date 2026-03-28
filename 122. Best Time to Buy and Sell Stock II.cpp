//RECURRSION
//TC: O(2^n)
//SC: O(n) - auxiliary stack space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return f(0,1,prices);
    }

    int f(int ind, int buy, vector<int>& prices){
        if(ind == prices.size()) return 0;
        if(buy){
            int Buy = -prices[ind] + f(ind+1, 0, prices);
            int notBuy = 0 + f(ind+1,1, prices);
            return max(Buy, notBuy);
        }
        else{
            int sell = prices[ind] + f(ind+1, 1, prices);
            int notSell = 0 + f(ind+1,0, prices);
            return max(sell, notSell);
        }
    }
};

//MEMOIZATION
//TC: O(n *2)
//SC: O(n*2) + O(n) - dp array size + auxiliary stack space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0,1,prices, dp);
    }

    int f(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            int Buy = -prices[ind] + f(ind+1, 0, prices, dp);
            int notBuy = 0 + f(ind+1,1, prices, dp);
            return dp[ind][buy] = max(Buy, notBuy);
        }
        else{
            int sell = prices[ind] + f(ind+1, 1, prices, dp);
            int notSell = 0 + f(ind+1,0, prices, dp);
            return dp[ind][buy] = max(sell, notSell);
        }
    }
};

//TABULATION
//TC: O(n *2)
//SC: O(n*2) - dp array size
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // dp[n][0] = dp[n][1] = 0 already

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    int Buy = -prices[i] + dp[i + 1][0];
                    int notBuy = dp[i + 1][1];
                    dp[i][buy] = max(Buy, notBuy);
                } else {
                    int sell = prices[i] + dp[i + 1][1];
                    int notSell = dp[i + 1][0];
                    dp[i][buy] = max(sell, notSell);
                }
            }
        }

        return dp[0][1];
    }
};


//OPTIMAL
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int max = 0;
    int start = prices[0];
    for(int i = 1;i<prices.size(); i++){
        if(start < prices[i]){
            max += prices[i] - start;
        }
        start = prices[i];
    }
    return max;
    }
};
