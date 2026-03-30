//RECURRSION
//TC: O(2^n)
//SC: O(n) - auxiliary stack space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cap = 2;
        return f(0,1,prices, cap);
    }

     int f(int ind, int buy, vector<int>& prices, int cap){
        if(ind == prices.size()) return 0;
        if(cap == 0) return 0;
        if(buy){
            int Buy = -prices[ind] + f(ind+1, 0, prices, cap);
            int notBuy = 0 + f(ind+1,1, prices, cap);
            return max(Buy, notBuy);
        }
        else{
            int sell = prices[ind] + f(ind+1, 1, prices, cap-1);
            int notSell = 0 + f(ind+1,0, prices, cap);
            return max(sell, notSell);
        }
    }
};

//MEMOIZATION
//TC: O(n*2*2)
//SC: O(n*2*3) + O(n) - dp array size + auxiliary stack space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cap = 2, n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,prices, cap, dp);
    }

     int f(int ind, int buy, vector<int>& prices, int cap, vector<vector<vector<int>>> &dp){
        if(ind == prices.size() || cap == 0) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(buy){
            int Buy = -prices[ind] + f(ind+1, 0, prices, cap, dp);
            int notBuy = 0 + f(ind+1,1, prices, cap, dp);
            return dp[ind][buy][cap] = max(Buy, notBuy);
        }
        else{
            int sell = prices[ind] + f(ind+1, 1, prices, cap-1, dp);
            int notSell = 0 + f(ind+1,0, prices, cap, dp);
            return dp[ind][buy][cap] = max(sell, notSell);
        }
    }
};

//TABULATION
//TC: O(n*2*3)
//SC: O(n*2*3) - dp array size
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cap = 2, n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

        for(int buy = 0; buy<=1; buy++){ // when ind == n return 0;
            for(int cap =1; cap<=2; cap++){
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
                for(int cap=1; cap<=2; cap++){
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

        return dp[0][1][2];
    }
};
